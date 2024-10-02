#include <stdio.h> 

void summing() {
    int a, b;
    printf("Bitte geben Sie eine Zahl ein: ");
    scanf("%d", &a);
    printf("Bitte geben Sie noch eine Zahl ein: ");
    scanf("%d", &b);
    printf("Die Summe von %d und %d ist %d.\n", a, b, (a+b)); 
}

int quer(int a) {
    int sum1 = 0;

    for (int i = 10; a != 0;) {
        sum1 = sum1 + a%i;
        a = (a - a%i)/i;
    }
    
    return sum1;
}

void quer3(int a) {
    if (quer(a)%3 == 0) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

int main() {

    printf("%d\n", quer(100));
    quer3(123621);
    
    return 0;
}