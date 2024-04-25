#ifndef MEMALLOCATOR_H
#define MEMALLOCATOR_H

#include <stddef.h>
#include <pthread.h>
#include <unistd.h>

typedef char ALIGN[16];

union header {
    struct {
        size_t size;
        unsigned is_free;
        union header *next;
    } s;
    ALIGN stub;
};

typedef union header header_t;

extern pthread_mutex_t global_malloc_lock;
extern header_t *head, *tail;

void *malloc(size_t size);
void free(void *block);
void *calloc(size_t num, size_t nsize);
void *realloc(void *block, size_t size);
header_t *get_free_block(size_t size);

#endif /* MEMALLOCATOR_H */
