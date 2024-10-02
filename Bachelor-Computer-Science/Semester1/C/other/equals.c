#include <stdio.h>

int equals(char *c1, char *c2){
  int i = 0;

  for (i = 0; (('\0' != *(c1 + i)) || ('\0' != *(c2 + i))); i++) {
    if (*(c1 + i) == *(c2 + i)) {
    }
    else {
      return 0;
    }
  }
  return 1;
}


int main() {
  char c1[20], c2[20];

  printf("Enter string 1: ");
  scanf("%s", c1);

  printf("Enter string 2: ");
  scanf("%s", c2);

  printf("Comparison result: %d\n", equals(c1, c2));

  return 0;
}
