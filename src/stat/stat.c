// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <sys/stat.h>

int stat(const char *restrict path, struct stat *restrict buf) {
  /* TODO: Implement stat(). */
  // sys_stat = 4
  int fd = syscall(4, path, buf);

  if (fd < 0) {
    errno = -fd;
    return -1;
  }

  return fd;
}
