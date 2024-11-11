#ifndef _TIME_H
#define _TIME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>
typedef long time_t;

struct timespec {
  long int tm_sec;  // secunde
  time_t tm_nsec;   // nanosecunde
};

int nanosleep(const struct timespec *timp_cerut, struct timespec *timp_ramas);

#ifdef __cplusplus
}
#endif
#endif
