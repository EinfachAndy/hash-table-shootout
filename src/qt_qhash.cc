#include <inttypes.h>
#include <functional>
#include <string>

#include <QHash>
typedef QHash<int64_t, int64_t> hash_t;

#define SETUP hash_t hash;

#define RESERVE_INT(size) hash.reserve(size);
#define LOAD_FACTOR(map) 0.0f

#define INSERT_INT_INTO_HASH(key, value) hash.insert(key, value)
#define DELETE_INT_FROM_HASH(key) hash.remove(key)
#define FIND_INT_EXISTING_FROM_HASH(key)                                                                               \
    if (hash.find(key) == hash.end()) {                                                                                \
        printf("error");                                                                                               \
        exit(1);                                                                                                       \
    }
#define FIND_INT_MISSING_FROM_HASH(key)                                                                                \
    if (hash.find(key) != hash.end()) {                                                                                \
        printf("error");                                                                                               \
        exit(2);                                                                                                       \
    }
#define FIND_INT_EXISTING_FROM_HASH_COUNT(key, count)                                                                  \
    if (hash.find(key) != hash.end()) {                                                                                \
        count++;                                                                                                       \
    }
#define CHECK_INT_ITERATOR_VALUE                                                                                       \
    for (auto it = hash.begin(); it != hash.end(); ++it) {                                                             \
        if (it.value() != value) {                                                                                     \
            printf("error");                                                                                           \
            exit(3);                                                                                                   \
        }                                                                                                              \
    }

#include "template.c"
