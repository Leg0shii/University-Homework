#include <stdio.h>

double array_sum(double *ns, int a) {
    double sum = 0;

    for(int i = 0; i < a; i++) {
        sum = sum + *(ns+i);
    }

    return sum;
}

void print_array(int a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d   ", a[i][j]);
        }
        printf("\n");
    }
    
}

int main() {

    // double ns[] = {3.0, 4.0, 5.0, 0.001};
    // printf("Summe: %f\n", array_sum(ns, 4));

    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9} 
    };

  print_array(arr);

    return 0;
} 



