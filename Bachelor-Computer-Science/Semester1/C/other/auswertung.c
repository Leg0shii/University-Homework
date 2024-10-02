#include <stdio.h>

void findTitle() {
  int a, b, i, j, save, save2, save3;

  a = getchar();
  putchar(a);

  for(i = 0; a != EOF; i++) {
    save3 = save2;
    save2 = save;
    save = a;
    a = getchar();
    if (a == 45) {
      a = getchar();
      if(a == 32) {
        a = getchar();
        if (a == 32) {
          a = getchar();
          while (a != '\n') {
            putchar(a);
            a = getchar();
            if (a == 45) {
              putchar(a);
              a = getchar();
              putchar(a);

              if (a == 32) {
                a = getchar();
                a = getchar();
                a = getchar();
                a = getchar();
                a = getchar();
              }
            }
          }
          putchar('|');
          if (save3 == 97 || save3 == 98) {
            putchar(save3);
          }
          putchar('\n');
          putchar('\n');
        }
      }
    }
  }
}


int main() {

  findTitle();

  return 0;
}
