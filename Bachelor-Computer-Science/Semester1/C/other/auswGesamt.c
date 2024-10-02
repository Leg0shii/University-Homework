#include <stdio.h>

int main(){

  char c;
  int nummer[] = {0,0,0,0,0,0,0,0};
  int i, j, h, y, z;

  c = getchar();

  for(i = 0; c != EOF; i++) {

    c = getchar();
      putchar(c);

    if (nummer[1] > 0) {
      y = getchar();
      z = getchar();
      if (y == 32) {
        putchar(y);
        putchar('\n');
        putchar('\n');
        putchar(z);
      }
      putchar('\n');
      for (h = 0; h < 20; h++) {
        putchar('*');
      }
      putchar('\n');
      putchar('\n');
      for (j = 0; j < 8; j++) {
        nummer[j] = 0;
      }
    }

    if ((c >= 48 && c <= 57) || c == 46) {
      if (c != 46) {
        nummer[0] = nummer[1];
        nummer[1] = nummer[2];
        nummer[2] = nummer[3];
        nummer[3] = nummer[4];
        nummer[4] = nummer[5];
        nummer[5] = nummer[6];
        nummer[6] = nummer[7];
        nummer[7] = c;
      }
    }
    else {
      for (j = 0; j < 8; j++) {
        nummer[j] = 0;
      }
    }


  }

  return 0;
}
