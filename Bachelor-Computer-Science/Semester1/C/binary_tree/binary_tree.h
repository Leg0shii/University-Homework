#include <stdio.h>
#include <stdlib.h>

typedef int Value;
typedef void (*VProc) (Value, int);
typedef struct _tree {
    Value v;
    struct _tree *left, *right, *parent;
} TreeRec, *Tree;

Tree empty();
Tree cons(Value v, Tree tl, Tree tr);
Tree left(Tree t);
Tree right(Tree t);
Tree parent(Tree t);
Value value(Tree t);
Tree insert(Value v, Tree t);
void inorder(Tree t, int level, VProc f);
int sizeTree(Tree t);