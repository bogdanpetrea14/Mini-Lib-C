// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	int err = syscall(__NR_close, fd);
	if (err < 0) {
		errno = err * (-1);
		return -1;
	}
	return err;
}
