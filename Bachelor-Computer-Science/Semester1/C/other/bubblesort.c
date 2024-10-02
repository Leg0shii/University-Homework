#include <stdio.h>

int main() {
    int arr[] = {3, 2, 9, 8, 1, 7, 5, 6, 4};
    int temp = 0;

    for(int i = 0; i < 8; i++) {
        for (int j = 0; j < 8-i; j++) {
            if (arr[j] >= arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }       
    }

    for (int k = 0; k < 9; k++) {
        printf("%d\n", arr[k]);
    }

    return 0;
}