#include <inttypes.h>
#include <oha/oha_fast.h>

static double
get_load_factor(struct oha_lpht * map)
{
    if (map == NULL) {
        return 0.0;
    }
    struct oha_lpht_status oha_status;
    if (oha_lpht_get_status(map, &oha_status) != 0) {
        exit(4);
    }
    oha_lpht_destroy(map);

    return oha_status.current_load_factor;
}

typedef struct oha_lpht * hash_t;

#define SETUP                                                                                                          \
    const struct oha_lpht_config config = {1024, 0.5, sizeof(uint64_t), sizeof(uint64_t), {0}, true};                  \
    hash_t hash;                                                                                                       \
    hash = oha_lpht_create(&config);                                                                                   \
    if (hash == NULL) {                                                                                                \
        fprintf(stderr, "create failed");                                                                              \
        exit(1);                                                                                                       \
    }                                                                                                                  \
    hash_t str_hash = NULL;

#define RESERVE_INT(size) oha_lpht_reserve(hash, size);
#define RESERVE_STR(size)
#define LOAD_FACTOR(map) get_load_factor(map)

#define INSERT_INT_INTO_HASH(key, value)                                                                               \
    void * val_insert = oha_lpht_insert(hash, &(key));                                                                 \
    if (val_insert == NULL) {                                                                                          \
        printf("insert failed\n");                                                                                     \
        exit(-5);                                                                                                      \
    }                                                                                                                  \
    memcpy(val_insert, &value, sizeof(value));

#define DELETE_INT_FROM_HASH(key) oha_lpht_remove(hash, &key);

#define FIND_INT_EXISTING_FROM_HASH(key)                                                                               \
    if (oha_lpht_look_up(hash, &key) == NULL) {                                                                        \
        printf("error");                                                                                               \
        exit(2);                                                                                                       \
    }

#define FIND_INT_MISSING_FROM_HASH(key)                                                                                \
    if (oha_lpht_look_up(hash, &key) != NULL) {                                                                        \
        printf("error");                                                                                               \
        exit(3);                                                                                                       \
    }

#define FIND_INT_EXISTING_FROM_HASH_COUNT(key, count)                                                                  \
    if (oha_lpht_look_up(hash, &key) != NULL) {                                                                        \
        count++;                                                                                                       \
    }

#define CHECK_INT_ITERATOR_VALUE                                                                                       \
    oha_lpht_iter_init(hash);                                                                                          \
    struct oha_key_value_pair pair;                                                                                    \
    for (oha_lpht_iter_init(hash); oha_lpht_iter_next(hash, &pair) == 0;) {                                            \
        if (*(uint64_t *)pair.value != value) {                                                                        \
            printf("error");                                                                                           \
            exit(3);                                                                                                   \
        }                                                                                                              \
    }

#include "template.c"
