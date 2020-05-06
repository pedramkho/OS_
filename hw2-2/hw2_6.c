#include <stdio.h>
#include <pthread.h>

void *function(void * args) {
  printf("5");
}

int main() {
  int i = 0;
  pthread_t id;
  int ret;
  ret = pthread_create(&id, NULL, &function, NULL);
  pthread_join(id, NULL);
  return 0;
}
