#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int z;
  int n;
} Bruch, *refBruch;

int ggt(int x, int y) {
  int c;
  if ( x < 0 ) x = -x;
  if ( y < 0 ) y = -y;
  while ( y != 0 ) {
    c = x % y;
    x = y;
    y = c;
  }
  return x;
}

int kgv(int x, int y){
  return (x * y / ggt(x,y));
}

void reduce(refBruch b) {
  int zaehler = b->z;
  int nenner = b->n;
  int ggt_zahl;

  ggt_zahl = ggt(zaehler, nenner);

  b->z = zaehler / ggt_zahl;
  b->n = nenner / ggt_zahl;
}

void print(refBruch b){
  int zaehler = b->z;
  int nenner = b->n;
  printf("%d / %d\n",zaehler,nenner);
}

refBruch add(refBruch b1, refBruch b2){
  refBruch sum = malloc(sizeof(int));

  int zaehler1 = b1->z;
  int nenner1 = b1->n;
  int zaehler2 = b2->z;
  int nenner2 = b2->n;
  int kgv_zahl, m1, m2;

  kgv_zahl = kgv(nenner1, nenner2);
  m1 = kgv_zahl / nenner1;
  m2 = kgv_zahl / nenner2;

  zaehler1 = zaehler1*m1;
  nenner1 = nenner1*m1;
  zaehler2 = zaehler2*m2;
  nenner2 = nenner2*m2;

  sum->z = zaehler1+zaehler2;
  sum->n = nenner2;

  return sum;
}

int compare (refBruch b1, refBruch b2){
  int nenner1 = b1->n;
  int zaehler1 = b1->z;
  int nenner2 = b2->n;
  int zaehler2 = b2->z;

  int kgv_zahl, m1, m2;
  int r;

  kgv_zahl = kgv(nenner1, nenner2);
  m1 = kgv_zahl / nenner1;
  m2 = kgv_zahl / nenner2;

  zaehler1 = zaehler1*m1;
  nenner1 = nenner1*m1;
  zaehler2 = zaehler2*m2;
  nenner2 = nenner2*m2;

  if (zaehler1 == zaehler2) {
    r = 0;
  }
  else if (zaehler1 < zaehler2) {
    r = -1;
  }
  else if (zaehler1 > zaehler2) {
    r = 1;
  }

  return r;
}

int main(){

  int i;
  Bruch rs[5] = {{1, 2}, {5, 2}, {1, 3}, {1, 4}, {3, 4}};

  qsort(rs, 5, sizeof(Bruch), (int (*)(const void *, const void *)) compare);

  for (i = 0; i < 5; i++) {
    print(rs + i);
    printf("\n");
  }

  return 0;
}
