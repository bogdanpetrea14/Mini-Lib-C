// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	int err = syscall(__NR_truncate, path, length);
	if (err < 0) {
		errno = err * (-1);
		return -1;
	}
	return err;
}
