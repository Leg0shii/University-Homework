#include <stdio.h>
#include <stdio.h>

int* number() {
  int *n = malloc(sizeof(int));
  *n = 4;
  return n;
}

int main() {
  int *n = number();
  printf("%d\n", *n);
  return 0;
}
