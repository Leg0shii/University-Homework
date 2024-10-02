#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int getPivot(int arr[], int low, int high) {
    int p[3], piv, r;
    for(int i = 0; i < 3; i++) {
        r = (rand() % ((high + 1) - low)) + low;
        printf("high: %d, low: %d, r: %d\n", high, low, r);
        p[i] = arr[r];
    } 
    if ((p[0] <= p[1] && p[1] <= p[2]) || (p[2] <= p[1] && p[1] <= p[0])) { piv = p[1]; }
    else if ((p[1] <= p[2] && p[2] <= p[0]) || (p[0] <= p[2] && p[2] <= p[1])) { piv = p[2]; }
    else if ((p[2] <= p[0] && p[0] <= p[1]) || (p[1] <= p[0] && p[0] <= p[2])) { piv = p[0]; }
    printf("PIVOT: %d\n", piv);
    return piv;
}

int partition(int a[], int p, int r) { 
    int x; 
    int i, j;
    x = getPivot(a, p, r);
    i = p-1;
    j = r+1; 
    for (;;) {
        do i++; while(a[i]<x); 
        do j--; while(a[j]>x); 

        if(i>=j) return j; 
        swap(&a[i],&a[j]);
    }
    return j; 
}

void qsort1(int a[], int p, int r) { 
    int i, q;
    if(p < r) {
        q = partition(a,p,r); 
        qsort1(a,p,q); 
        qsort1(a,q+1,r);
    } 
}

void printArray(int arr[], int size)  { 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
}

int main() {
    int a[] = {4,2,6,7,9,1,2,5,8,10};
    int *b;
    srand(time(0));

    qsort1(a, 0, SIZE-1);
    printArray(a, SIZE);

    return 0;
}