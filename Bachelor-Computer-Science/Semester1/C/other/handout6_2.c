#include <stdio.h>

int array_sum(double *ns, int a) {
    int sum = 0;

    for(int i = 0; i < a; i++) {
        sum = sum + ns[i];
    }

    return sum;
}

int main() {

    double ns[] = {3.0, 4.0, 5.0, 0.001};

    printf("Summe: %f\n", array_sum(ns, 4));

    return 0;
} 
