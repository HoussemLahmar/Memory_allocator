#ifndef PTHREAD_H
#define PTHREAD_H

#include <sched.h>
#include <time.h>
#include <unistd.h>

#define PTHREAD_MUTEX_INITIALIZER 0

typedef int pthread_mutex_t;

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
int pthread_mutex_init(pthread_mutex_t *mutex, const void *attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex);

#endif /* PTHREAD_H */
