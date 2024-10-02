#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000
int store[SIZE];
int count = 0;

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void searchSort(int* a, int l, int r) {
    int i;
    bool token = true;
    static int storeindex = 0;
    if (l == r) {
        for(int j = 0; j < SIZE-1; j++) {
            if(a[j] > a[j+1]) {
                token = false;
            }
        }
        if(token) {
            for(int j = 0; j < SIZE; j++) {
                store[j] = a[j];
            }
        }
        storeindex++;
    }
    else {
        for (i = l; i <= r; i++) {
            swap((a+l), (a+i));
            searchSort(a, l+1, r);
            swap((a+l), (a+i));
        }
    }
}

int *bubblesort(int a[SIZE]) {
    int temp;
    for(int i = 1; i < SIZE; i++) {
        for(int j = 0; j < SIZE-i; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    return a;
}

int *shellSort(int a[SIZE]) {
    int i, j, k, tmp;
    for(i = SIZE/2; i > 0; i = i / 2) {
        for(j = i; j < SIZE; j++) {
            for(k = j - i; k >= 0; k - i) {
                if(a[k+i] >= a[k]) break;
                else {
                    tmp = a[k];
                    a[k] = a[k+i];
                    a[k+i] = tmp;
                }
            }
        }
    }
    return a;
}

int *initArray(int n) {
    int *a = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) {
        a[i] = n-i;
    }
    return a;
}

int *initArrayRandom(int n) {
    int *a = malloc(n*sizeof(int));
    int r;
    for(int i = 0; i < n; i++) {
        r = rand() % 1000 + 1;
        a[i] = r;
    }
    return a;
}

int getPivot(int arr[], int low, int high) {
    int p[3], piv, r;
    for(int i = 0; i < 3; i++) {
        r = (rand() % ((high + 1) - low)) + low;
        //printf("high: %d, low: %d, r: %d\n", high, low, r);
        p[i] = arr[r];
    } 
    if ((p[0] <= p[1] && p[1] <= p[2]) || (p[2] <= p[1] && p[1] <= p[0])) { piv = p[1]; }
    else if ((p[1] <= p[2] && p[2] <= p[0]) || (p[0] <= p[2] && p[2] <= p[1])) { piv = p[2]; }
    else if ((p[2] <= p[0] && p[0] <= p[1]) || (p[1] <= p[0] && p[0] <= p[2])) { piv = p[0]; }
    //printf("PIVOT: %d\n", piv);
    return piv;
}

int partition(int a[], int p, int r) { 
    int x; 
    int i, j;
    //x = getPivot(a, p, r);
    x = a[p];
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
    double time1 = 0.0, tstart;
    double timeArr[12];
    double sum = 0.0, sum2 = 0.0, var = 0.0;
    double meanV, standD;
    srand(time(0));

    int *a10, *a100, *a1000, *a10000, *a100000, *a1000000;

    /*a10 = initArray(SIZE);
    time1 = 0.0;
    tstart = clock();
    qsort1(a10, 0, SIZE-1);
    time1 = time1 + clock() - tstart;
    time1 = time1/CLOCKS_PER_SEC;

    printf("%f\n", time1);*/



    for (int i = 0; i < 12; i++) {
        a10 = initArrayRandom(SIZE);
        time1 = 0.0;
        tstart = clock();
        qsort1(a10, 0, SIZE-1);
        time1 = time1 + clock() - tstart;
        timeArr[i] = time1/CLOCKS_PER_SEC;
        sum = (time1/CLOCKS_PER_SEC + sum);
    }
    meanV = sum/12;
    for(int j = 0; j < 12; j++) {
        var = var + ((timeArr[j] - meanV)*(timeArr[j] - meanV));
    }
    standD = sqrt(var/12);
    printf("//  Mittelwert: %.7fs\n", meanV);
    printf("//  Standardabweichung: %.7fs\n", standD);

    return 0;
}

    //searchsort
        //sortiert
            //10:   0.156s
            //100: +30min
        //rückwärts-sortiert
            //10:   0.173s
            //100: +30min
        //zufall
            //10:  Mittelwert:         0.1802367s
            //     Standardabweichung: 0.0052170s
            //100: Mittelwert:         +30min
            //     Standardabweichung: -
    
    //bubblesort
        //sortiert
            //10:      0.000002s
            //100:     0.000011s
            //1000:    0.001419s
            //10000:   0.0966s
            //100000:  10.024s
            //1000000: 16min
        //rückwärts-sortiert
            //10:      0.000003s
            //100:     0.000037s
            //1000:    0.002417s
            //10000:   0.170533s
            //100000:  17.1s
            //1000000: +30min
        //zufall
            //10:      Mittelwert:         0.0000013s
            //         Standardabweichung: 0.0000005s
            //100:     Mittelwert:         0.0000439s
            //         Standardabweichung: 0.0000016s
            //1000:    Mittelwert:         0.0024413s
            //         Standardabweichung: 0.0005493s
            //10000:   Mittelwert:         0.2211851s
            //         Standardabweichung: 0.0031853s
            //100000:  Mittelwert:         26.6191330s
            //         Standardabweichung: 0.2628273s
            //1000000: Mittelwert:         +30min
            //         Standardabweichung: ???
    
    //shellsort
        //sortiert
            //10:      0.000003s
            //100:     0.000006s
            //1000:    0.000038s
            //10000:   0.000307s
            //100000:  0.005189s
            //1000000: 0.044246s
        //rückwärts-sortiert
            //10:      0.000003s
            //100:     0.000006s
            //1000:    0.000038s
            //10000:   0.000307s
            //100000:  0.005189s
            //1000000: 0.044246s
        //zufall
            //10:      Mittelwert:         0.0000006s
            //         Standardabweichung: 0.0000008s
            //100:     Mittelwert:         0.0000123s
            //         Standardabweichung: 0.0000005s
            //1000:    Mittelwert:         0.0001453s
            //         Standardabweichung: 0.0000136s
            //10000:   Mittelwert:         0.0009773s
            //         Standardabweichung: 0.0000109s
            //100000:  Mittelwert:         0.0114906s
            //         Standardabweichung: 0.0002598s
            //1000000: Mittelwert:         0.2740172s
            //         Standardabweichung: 0.0005377s

    //quicksort-median
        //sortiert
            //10:      0.000006s
            //100:     0.000016s
            //1000:    0.000213s
            //10000:   0.001142s
            //100000:  0.012114s
            //1000000: 0.131583s
        //rückwärts-sortiert
            //10:      0.000008s
            //100:     0.000018s
            //1000:    0.000208s
            //10000:   0.001181s
            //100000:  0.018955s
            //1000000: 0.130297s
        //zufall
            //10:      Mittelwert:         0.0000027s
            //         Standardabweichung: 0.0000008s
            //100:     Mittelwert:         0.0000238s
            //         Standardabweichung: 0.0000015s
            //1000:    Mittelwert:         0.0002555s
            //         Standardabweichung: 0.0000046s
            //10000:   Mittelwert:         0.0025013s
            //         Standardabweichung: 0.0000153s
            //100000:  Mittelwert:         0.0246412s
            //         Standardabweichung: 0.0002080s
            //1000000: Mittelwert:         0.2621096s
            //         Standardabweichung: 0.0082658s

    //quicksort-normal
        //sortiert
            //10:      0.000002s
            //100:     0.000024s
            //1000:    0.001986s
            //10000:   0.097930s
            //100000:  8.848755s
            //1000000: ca 15min
        //rückwärts-sortiert
            //10:      0.000003s
            //100:     0.000024s
            //1000:    0.000937s
            //10000:   0.088778s
            //100000:  8.948910s
            //1000000: ca 15min
        //zufall
            //10:      Mittelwert:         0.0000013s
            //         Standardabweichung: 0.0000008s
            //100:     Mittelwert:         0.0000145s
            //         Standardabweichung: 0.0000013s
            //1000:    Mittelwert:         0.0001710s
            //         Standardabweichung: 0.0000032s
            //10000:   Mittelwert:         0.0015633s
            //         Standardabweichung: 0.0002857s
            //100000:  Mittelwert:         0.0112093s
            //         Standardabweichung: 0.0013889s
            //1000000: Mittelwert:         0.1123669s
            //         Standardabweichung: 0.0015308s


