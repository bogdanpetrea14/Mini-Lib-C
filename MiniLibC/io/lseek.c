// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	int err = syscall(__NR_lseek, fd, offset, whence);
	if (err < 0) {
		errno = err * (-1);
		return -1;
	}
	return err;
}
