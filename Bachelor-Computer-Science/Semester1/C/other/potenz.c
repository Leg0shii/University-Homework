#include <stdio.h>
#define N 16
#define X 2

int power(int x, int n) {
int xn;

for(xn=1; n>0; --n) xn = xn * x;
  return xn;
}

main () {
  int i;
  for(i=0;i<=N;++i)
    printf("%d^%d = %d\n",X,i,power(X,i));
}
