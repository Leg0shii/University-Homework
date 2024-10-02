#include <stdio.h>

int isPrime(int a){
  int i;
  int c = 0;
  for (i = 1; i <= a; i++) {
    if (a%i == 0){
      c = c + 1;
    }
  }
  if (c == 2) {
    return a;
  }
  else {
    return 0;
  }
}

void grenze(int b){
int i = 0;
int k = 0;
  for (i = 2; i <= b; i++) {
    k = isPrime(i);
    if(k>1){
      printf("%d\n",k);
    }
  }
}

int main() {

  int x;
  printf("Deine Grenze?\n");
  scanf("%d",&x);
  grenze(x);

}
