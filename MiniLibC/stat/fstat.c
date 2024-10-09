// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	int err = syscall(__NR_fstat, fd, st);
	if (err < 0) {
		errno = err * (-1);
		return -1;
	}
	return err;
}
