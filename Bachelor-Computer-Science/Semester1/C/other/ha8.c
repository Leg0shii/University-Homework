#include <stdio.h>

/* Aufgabe 1.1 */
void teiler_f(){
  int a;
  for (a = 30; a > 2; a = a - 3) {
    printf("%d\n",a);
  }
}

void teiler_w() {
  int a = 30;
    while(a > 2){
      printf("%d\n",a);
      a = a - 3;
  }
}

void teiler_dw(){
  int a = 30;
  do {
    printf("%d\n",a);
    a = a - 3;
  } while (a>2);
}

int teiler_r(int a){
  if (a>3) {
    a = a - 3;
    printf("%d\n",a);
    teiler_r(a);
  }
  return 0;
}

/* Aufgabe 1.2 */
int array_sum_rec(int* a, int b){
  int z = 0;

  if(b>0){
    z = a[b-1] + array_sum_rec(a,b-1);
  }

  return z;
}

int array_sum_iter(int* a, int b){
  int z;
  b = b - 1;
  if (b==0) {
    z = 0;
  }
  else{
    while (b>=0) {
      z = a[b] + z;
      b = b - 1;
    }
  }

  return z;
}

/* Aufgabe 1.3 */
int max_rec(int* a, int b){
  int x = 0;
  if (b>=0) {
    if (x < a[b-1]) {
      x = a[b-1];

    }
  }
  return x;
}

int max_it(int* a, int b){
  int x = 0;
  while (b>=0){
    if(x < a[b-1]){
      x = a[b-1];
    }
    b = b - 1;
  }
return x;
}


int main(){

  int three_nums[] = {1, 42, 3, 7, 9};
  printf("%d\n", max_it(three_nums, 5));


return 0;
}
