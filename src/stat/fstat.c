// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	// sys_fstat = 5;
	int resf = syscall(5, fd, st);

	if (resf < 0) {
    	errno = -resf;
    	return -1;
  }

  return resf;
}
