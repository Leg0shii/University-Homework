#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int zaehler;
    int nenner;
} Bruch, *RefBruch;

void print(RefBruch bruch) {
    printf("%d / %d\n", bruch->zaehler, bruch->nenner);
}

int ggt5(int x, int y) { 
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

void reduce(RefBruch bruch) {
    int ggt = 0;
    ggt = ggt5(bruch->zaehler, bruch->nenner);
    bruch->zaehler = bruch->zaehler/ggt;
    bruch->nenner = bruch->nenner/ggt;   
}

int kgv5(int a, int b) {
  return a * b / ggt5(a, b);
}

RefBruch add(RefBruch b1, RefBruch b2) {
    int kgv1;
    RefBruch b3;
    kgv1 = kgv5(b1->nenner, b2->nenner);
    int zahl1, zahl2;
    zahl1 = kgv1 / b1->nenner;
    zahl2 = kgv1 / b2->nenner;
    b3->zaehler = b1->zaehler*zahl1+b2->zaehler*zahl2;
    b3->nenner= b1->nenner*zahl1;
    reduce(b3);

    return b3;
}

int main() {

    Bruch b1;
    Bruch b2;
    RefBruch b3;

    b1.zaehler = 1;
    b1.nenner = 2;
    b2.zaehler = 1;
    b2.nenner = 4;

    b3 = add(&b1, &b2);

    print(b3);


    


    return 0;
}