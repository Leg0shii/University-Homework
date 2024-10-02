#include <stdio.h>

int main() {
  int number, index, i;

  scanf("%d",&number);
  scanf("%d",&index);

  for (i = 0; i < index; i++) {
    
    if (number % 10 == 0) {
      number = number / 10;
    }
    else {
      number = number - 1;
    }
  }

  printf("%d\n",number);


  return 0;
}
