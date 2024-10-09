// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	int err = syscall(__NR_ftruncate, fd, length);
	if (err < 0) {
		errno = err * (-1);
		return -1;
	}
	return err;
}
