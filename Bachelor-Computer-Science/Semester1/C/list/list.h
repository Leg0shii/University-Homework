#include <stdio.h>
#include <stdlib.h>

typedef int Value;
typedef void (*VProc) (Value);
typedef enum {False, True} Bool;

typedef struct _list {
  Value val;
  struct _list *next;
} Elem, *List;

List init(void);
List insert(Value, List);
void print(List);
Bool empty(List);
Value head(List);
List tail(List);
unsigned int length(List);
Value nth(List, unsigned int);
List map(List, int (*)(int));
Value last(List);
List delete(List, int);
Bool isSorted(List);
