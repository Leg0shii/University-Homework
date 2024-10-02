#include <stdio.h>


void cbr(int *a, int l, int **x, int **y){
  int min = 100;
  int max = 0;

  int *h1 = &min;
  int *h2 = &max;

  int i = 0;

  for(i = 0; i < l; i++){

    if(min > *(a + i)){
      min = *(a + i);
    }

    if(max < *(a + i)){
      max = *(a + i);
    }

  }

  *x = h1;
  *y = h2;
}


int main() {

  int l = 5;
  int f[] = {40,3,2,5,2};
  int *x;
  int *y;

  cbr(f, l, &x, &y);
  printf("%d,%d\n",*x, *y);

  return 0;
}
