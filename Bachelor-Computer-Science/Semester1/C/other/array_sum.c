#include <stdio.h>

double array_sum(double a[], int z) {
int i;
double x;
  for (i = 0; i<z; i++) {
    x = a[i] + x;
  }
return x;
}

int main() {

double ns[] = {1.0,2.0,3.0};

printf("Summe: %f\n",array_sum(ns, 3));

}
