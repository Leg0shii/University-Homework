#include <stdio.h>

int quer(int b){
  int d = 0;
  if (b>0) {
    d = quer(b/10);
    d = d + b%10;
  }
  return d;
}


int main() {

  int a = 0;
  int d = 0;

  printf("Deine Zahl\n");
  scanf("%d",&a);

  d = quer(a);
  printf("%d\n",d);
  return 0;

}
