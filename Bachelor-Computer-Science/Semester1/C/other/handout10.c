#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *author;
  char *title;
} Book, *BookRef;

int main () {
  int i, size;
  char *author;
  char temp[100];

  scanf("%s",temp);
  for(i = 0; ('\0' != temp[i]) ;i++){
    size = i;
  }
  size = size + 1;
  author = malloc(size * sizeof(char));
  strcpy(author,temp);

  printf("%s\n",author);

  BookRef a;
  a = malloc(sizeof(Book));
  /* TODO read in values for author and title */
  free(a);
}
