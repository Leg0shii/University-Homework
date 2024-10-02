#include <stdio.h>

void print_array(int a[3][3]){
int i1;
int i2;
  for (i1 = 0; i1<3; i1++) {
    printf(" \n");
    for (i2 = 0; i2<3; i2++) {
      printf("%d  ",a[i1][i2]);
    }
  }
}

int main() {

int arr[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
                };
  print_array(arr);
return 0;
}
