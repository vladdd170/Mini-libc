// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *malloc(size_t size) {
  /* TODO: Implement malloc(). */

  void *alocare = mmap(NULL, size, PROT_WRITE | PROT_READ,
                       MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

  if (alocare == MAP_FAILED) return NULL;
  mem_list_add(alocare, size);
  return alocare;
}

void *calloc(size_t nmemb, size_t size) {
  /* TODO: Implement calloc(). */
  size_t dimensiuneAlocare = nmemb * size;
  void *struc = malloc(dimensiuneAlocare);

  // Programare defensiva
  if (struc == NULL) return NULL;

  memset(struc, 0, dimensiuneAlocare);
  mem_list_add(struc, dimensiuneAlocare);
  return struc;
}

void free(void *ptr) {
  /* TODO: Implement free(). */
  struct mem_list *delete = mem_list_find(ptr);
  size_t len = delete->len;

  // int munmap(void *addr, size_t len);
  munmap(ptr, len);
  mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size) {
  /* TODO: Implement realloc(). */
  struct mem_list *realocare = mem_list_find(ptr);
  size_t vechea_lungime = realocare->len;

  mem_list_del(ptr);
  void *alocare = mremap(ptr, vechea_lungime, size, MREMAP_MAYMOVE);

  if (alocare == MAP_FAILED) return NULL;
  mem_list_add(alocare, size);
  return alocare;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
  /* TODO: Implement reallocarray(). */
  // Implementare din GNU Libc manual ;)
  return realloc(ptr, nmemb * size);
}
