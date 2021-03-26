#include <inttypes.h>
#include <string>
#include <google/sparse_hash_map>

typedef google::sparse_hash_map<int64_t, int64_t, std::hash<int64_t> > hash_t;

#define SETUP                                                                                                          \
    hash_t hash;                                                                                                       \
    hash.set_deleted_key(-1);

#define RESERVE_INT(size) hash.resize(size);
#define LOAD_FACTOR(map) map.load_factor()

#define INSERT_INT_INTO_HASH(key, value) hash.insert(hash_t::value_type(key, value))
#define DELETE_INT_FROM_HASH(key) hash.erase(key)
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
        if (it->second != value) {                                                                                     \
            printf("error");                                                                                           \
            exit(3);                                                                                                   \
        }                                                                                                              \
    }

#include "template.c"
