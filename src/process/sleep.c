#include <../include/time.h>
#include <errno.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>

int nanosleep(const struct timespec *timp_cerut, struct timespec *timp_ramas) {
  // sys_nanosleep = 35
  long reznan = syscall(35, timp_cerut, timp_ramas);

  if (reznan < 0) {
    errno = -reznan;
    return -1;
  }

  return reznan;
}

unsigned int sleep(unsigned int seconds) {
  struct timespec time;
  time.tm_nsec = 0;
  time.tm_sec = seconds;

  int reznan2 = nanosleep(&time, NULL);

  return reznan2;
}
