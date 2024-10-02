#include <stdlib.h>
#include <stdio.h>
typedef struct _elem {
  int value;
  struct _elem *next;
} ElemRec, *Elem;

typedef Elem Liste;

void insert (int v, Liste *list) {
  Elem newElem = malloc (sizeof (ElemRec));
  newElem->value = v;
  newElem->next = NULL;
  if (*list == NULL) {
      *list = newElem;
    }
  else {
      Elem runner = *list;
      while (runner->next != NULL) {
	    runner = runner->next;
	  }
      runner->next = newElem;
    }
}

Elem removeFirst (Liste *list) {
  Elem k = *list;
  if (k->next != NULL) {
    *list = k->next;
  }
  else {
    *list = NULL;
    k = *list;
  }
    return k;
}

void insertCorrect (Elem e, Liste *list) {	
    int temp;
    Elem k = *list;
    insert(e->value, list);
    
    while (k->next != NULL) {
      if (e->value < k->value) {
        temp = k->value;
        k->value = k->next->value;
        k->next->value = temp;
        k = k->next;
      }
      else {
        k = k->next;
      }
    }
}

void sort (Liste *list) {	
    Liste l = NULL;
    Elem e;
    Elem k;
    e = *list;

    while (e->next != NULL) {
      k = removeFirst(list);
      insertCorrect(k, &l);
    }

    *list = l;
}

int main () {
  Liste list = NULL;
  insert (1, &list);
  insert (2, &list);
  insert (4, &list);
  insert (6, &list);
  insert (9, &list);

  sort(&list);
/* list -> 5 -> 4 -> 7 -> 3 -> 2 -> NULL */
}