#include <stdio.h>

void octal(int b){
  if (b>0){
    octal(b/8);
    printf("%d",b%8);
  }
}

int main() {
  int a = 0;

  printf("Deine Zahl\n");
  scanf("%d",&a);

  octal(a);
  printf("\n");
  return 0;
}
