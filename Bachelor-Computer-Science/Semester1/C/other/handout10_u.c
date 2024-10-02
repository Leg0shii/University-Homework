
#include <stdio.h> 
#include <stdlib.h>

typedef struct { 
    char *author; 
    char *title;
} Book, *BookRef;

int arrayLength(char arr[100]) {
    int i;
    for (i = 0; arr[i] == '\0'; i++) {}
    
    return i;
}


int main () {
    BookRef a;
    a = malloc(sizeof(Book));
    char arr[100];
    scanf("%s", arr);
    a->author = malloc((arrayLength(arr)+1)*sizeof(char));
    scanf("%s", arr);
    a->title = malloc((arrayLength(arr)+1)*sizeof(char));

    /* TODO read in values for author and title */ 
    //free(a);
    return 0;
}