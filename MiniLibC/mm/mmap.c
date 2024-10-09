// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long err = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (err < 0) {
		errno = err * (-1);
		return MAP_FAILED;
	}
	return (void *)err;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long err = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (err < 0) {
		errno = err * (-1);
		return MAP_FAILED;
	}
	return (void *)err;
}

int munmap(void *addr, size_t length)
{
	long err = syscall(__NR_munmap, addr, length);
	if (err < 0) {
		errno =  err * (-1);
		return -1;
	}
	return err;
}
