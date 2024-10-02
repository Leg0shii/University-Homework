#include <stdio.h>

void swap(double **a, double **b){

  double *c = *a;
  *a = *b;
  *b = c;

}

int main() {

  double x = 3.0, y = 5.0;
  double *a = &x, *b = &y;

  printf("x = %0.1f, y = %0.1f, *a = %0.1f, *b = %0.1f\n",x,y,*a,*b);
  swap(&a, &b);
  printf("x = %0.1f, y = %0.1f, *a = %0.1f, *b = %0.1f\n",x,y,*a,*b);

  return 0;
}
