// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	// sys_mmap = 9
	long long fid = syscall(9, addr, length, prot, flags, fd, offset);

	if( fid < 0 ) {
		errno = -fid;
		return MAP_FAILED;
	}

	return (void *)fid;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	// sys_mremap = 25;
	long long fid = syscall(25, old_address, old_size, new_size, flags);

    if (fid < 0) {
		errno = -fid;
        return MAP_FAILED;
	}

	return (void *)fid;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	// sys_munmap = 11

	int fid = syscall(11, addr, length);

    if (fid < 0) {
		errno = -fid;
    	return -1;
	}

    return fid;
}
