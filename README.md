# Philosophers| 42 project| Threads and Mutex

**`#include <pthread.h>`**
### General Thread Functions

**`pthread_join`** is **waiting for a thread to teminate**, collecting return value as a string inside `retval` pointer, on success - NULL is returned.
>int     pthread_join(pthread_t thread, void **retval)

**`pthread_create`** **starts a new thread**, `thread` returns thread ID, `attr` can be NULL for default, `void * (*start_routine)` pointer to function which takes `void *`, `arg` is argument for the function
>int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);

**`pthread_detach`** marks the thread as detached, which means its resources are released to the system, with no need to `pthread_join`, returns 0 or errno
>int pthread_detach(pthread_t thread);

### Mutex Functions
**`pthread_mutex_init`** - `attr = NULL` for default, makes mutex *initialized and unlocked*
> int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);

**`pthread_mutex_destroy`** - it's only safe to destroy (make uninitialized) an initialized mutex that is unlocked
> int pthread_mutex_destroy(pthread_mutex_t *mutex);

**` pthread_mutex_lock`** 
> int pthread_mutex_lock(pthread_mutex_t *mutex);
**`pthread_mutex_unlock`**
> int pthread_mutex_unlock(pthread_mutex_t *mutex);

### Other unknown functions 
**` gettimeofday`**
> int gettimeofday(struct timeval *restrict tv, struct timezone *_Nullable restrict tz);
>
> struct timeval {
               time_t      tv_sec;     /* seconds */
               suseconds_t tv_usec;    /* microseconds */
           };
>
> struct timezone {
               int tz_minuteswest;     /* minutes west of Greenwich */
               int tz_dsttime;         /* type of DST correction */
           };

**`usleep`** - stop thread execution of the thread for min `usec` *microseconds*, 0 on success, -1 on err.
> int usleep(useconds_t usec);

## Sources
- [POSIX thread (pthread) libraries](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)
- [Dining Philosophers Problem (Wiki)](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Multithreading in C (GeeksforGeeks)](https://www.geeksforgeeks.org/multithreading-in-c/)

## TO-DO List
- [X] learn how new functions for threads and thread lock work
- [ ] learn about Dining Philosophers problem
- [ ] write a draft for my Philo solution
- [ ] check the coded C solutions available
- [ ] modify the draft of my solution
