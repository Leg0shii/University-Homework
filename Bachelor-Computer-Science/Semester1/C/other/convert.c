#include <stdio.h>

int big(int a){
  if (a>96 && a<123) {
    a = a - 32;
  }
  return a;
}

int main() {
  int a;
  while((a=getchar())!=EOF){
    a = big(a);
    putchar(a);
  }
  return 0;
}
