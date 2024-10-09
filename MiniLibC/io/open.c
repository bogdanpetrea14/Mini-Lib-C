// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	va_list arguments;
	va_start(arguments, flags);
	int err = syscall(__NR_open, filename, flags);
	va_end(arguments);
	if (err < 0) {
		errno = err * (-1);
		return -1;
	}
	return err;
}
