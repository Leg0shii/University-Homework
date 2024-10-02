#include <stdio.h>

int main() {
  int i, c;

  for (i = 0; c != EOF; i++) {
    c = getchar();
    printf("%d\n",i);
  }

  return 0;
}
