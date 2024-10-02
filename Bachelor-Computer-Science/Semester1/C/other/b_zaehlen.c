#include <stdio.h>

int bZuZahl(int a){
  if (a>64 && a<91 || a>96 && a<123){
    if (a>96 && a<123) {
      a = a - 32;
    }
    return a-64;
  }
  else{
    return 0;
  }
}

int main() {

  int arr[27];
  int i, z, b;
  char c;

  for (i = 0; i < 27; i++) {
    arr[i] = 0;
  }

  while(b!=EOF){
    b = getchar();
    z = bZuZahl(b);
    arr[z] = arr[z] + 1;
  }

  for (i = 1; i<27;i++) {
    putchar(i+96);
    printf(": %d\n",arr[i]);
  }

  return 0;
}
