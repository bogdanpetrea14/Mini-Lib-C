// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	int err = syscall(__NR_stat, path, buf);
	if (err < 0) {
		errno = err * (-1);
		return -1;
	}
	return err;
}
