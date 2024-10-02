#include <stdio.h>

int main() {

  int a;

  printf("Gib mir deine Zahl!\n");
  scanf("%d",&a); 
  printf("Deine binaere Zahl: ");

  while (a!=0) {
    if(a%2==0){
      a = a / 2;
      printf("0");
    }
    else {
      a = (a - 1)/2;
      printf("1");
    }
  }
  printf("\n");
  return 0;
}
