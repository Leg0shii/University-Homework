#include <stdio.h>


int quer(int n) {
    int sum = 0;
    if (n > 10) {
        sum = sum + n%10 + quer((n-n%10)/10);
    }
    else {
        if(n == 10) {
            sum = 1;
        }
        else {
            sum = n%10;
        }
    }
    return sum;
}

int main() {

    printf("%d\n", quer(20001));


    return 0;
}