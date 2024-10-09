#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;

    while (nanosleep(&req, &rem) == -1)
        req = rem;

    return rem.tv_sec;
}