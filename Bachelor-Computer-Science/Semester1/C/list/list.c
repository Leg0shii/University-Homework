#include "list.h"
#include <stdio.h>

List init() {
  return NULL;
}

List insert(Value v, List l) {
  List e = malloc(sizeof(Elem));
  e->val = v;
  e->next = l;
  return e;
}

Bool empty(List l){
  return l == NULL;
}

Value head(List l){
    if(l){
      return l->val;
    }
    else {
      printf("Error");
    }
}

List tail(List l){
  return l ? l->next : l;
}

Value nth(List l, unsigned int n){
  return n>0 ? nth(tail(l), n-1) : head(l);
}

List nthTail(List l, unsigned int n){
  List l1;
  if (n>0) {
    l1 = nthTail(tail(l), n-1);
  }
  return l1;
}

unsigned int length(List l){
  return empty(l) ? 0 : 1+length(tail(l));
}

void print(List l){
  while (!empty(l)) {
    printf("%d ", l->val);
    l = l->next;
  }
  printf("\n");
}

List map(List l, int (*fun)(int)){
  if (empty(l)) {
    return NULL;
  }
  else {
    List m;
    m = malloc(sizeof(Elem));
    m->val = fun(l->val);
    return insert(m->val, map(l->next, fun));
  }
}

Value last(List l){
  if (l->next == NULL){
    return l->val;
  }
  return last(l->next);
}

List delete(List l, int v){
  if (l->val == v){
    return l->next;
  }
  return insert(l->val, delete(l->next, v));
}

Bool isSorted(List l) {
  if (l->next == NULL) {
    return True;
  }
    return (l->val <= l->next->val && isSorted(l->next));
}
