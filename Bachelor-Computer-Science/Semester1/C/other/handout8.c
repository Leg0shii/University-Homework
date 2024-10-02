#include <stdio.h>

void forschleife() {
    for(int i = 30; i >= 3; i = i-3) {
        printf("%d\n", i);
    }
}

void whileschleife() {
    int n = 30;
    while (n >= 3) {
        printf("%d\n", n);    
        n = n - 3;
    }
}

void dowhileschleife() {
    int n = 30;
    do {
        printf("%d\n", n);
        n = n - 3;
    }
    while (n >= 3);
}

void rek(int n) {
    if (n >= 3) {
        printf("%d\n", n);
        rek (n-3);
    }
}

void swap(double **a, double **b) {
    double *c = *b;
    *b = *a;
    *a = c;
}

int main() {

    double x = 3.0;
    double y = 5.0;
    double *a = &x;
    double *b = &y;
    printf("x = %0.1f, x = %0.1f, *a = %0.1f, *b = %0.1f\n", x, y, *a, *b);
    //printf("*a: %f\n", *a);
    //printf("a: 0x%x\n", a);
    //printf("&a: %f\n", **&a);
    swap(&a, &b);
    printf("x = %0.1f, x = %0.1f, *a = %0.1f, *b = %0.1f\n", x, y, *a, *b); 
    

    return 0;
}