#include <stdio.h>

int main() {
  int i, a;

  a = getchar();
  putchar(a);

  for(i = 0; a != EOF; i++) {
    putchar(a);
    a = getchar();

    if (a == 13) {
      a = getchar();
    }

  }

  return 0;
}
