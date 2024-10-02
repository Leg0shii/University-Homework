#include <stdio.h>

int main(){

  int a;
  int seg;

  printf("Gib mir deine Zahl!\n");
  scanf("%d", &a);

  while(a!=0){
    seg = a%8;
    printf("%d",seg);
    a = a/8;
  }
  printf("\n");
  return 0;
}
