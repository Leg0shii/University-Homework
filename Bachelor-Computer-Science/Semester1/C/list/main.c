#include <stdio.h>
#include "list.h"

int times_two(int n){
  return 2 * n;
}

int main() {

  List l, m;

  l = insert(4, insert(5, insert(6, insert(9, NULL))));
  printf("%d",last(l));

  if (isSorted(l) == True) {
    printf("TRUE\n");
  }

  return 0;
}
