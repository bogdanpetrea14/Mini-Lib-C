#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int err = syscall(__NR_nanosleep, req, rem);
    if (err < 0) {
        errno = err * (-1);
        return -1;
    }
    return err;
}