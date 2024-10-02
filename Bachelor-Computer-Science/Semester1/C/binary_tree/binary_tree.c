#include "binary_tree.h"
#include <stdio.h>

#define errorvalue -1

Tree empty() { return NULL; }

Tree cons(Value v, Tree tl, Tree tr) {
    Tree tmp = (Tree)malloc(sizeof(TreeRec));
    if(tmp == NULL) {
        printf("{cons}Memory Full");
    } else {
        tmp->v = v;
        tmp->left = tl;
        tmp->right = tr;
        tmp->parent = NULL;
        if(tl) tl->parent = tmp;
        if(tr) tr->parent = tmp;
    }
    return tmp;
}

Tree left(Tree t) {
    Tree tmp = NULL;

    if(t == NULL) printf("Left Tree Empty");
    else tmp = t->left;

    return tmp;
}

Tree right(Tree t) {
    Tree tmp = NULL;

    if(t == NULL) printf("Right Tree Empty");
    else tmp = t->right;

    return tmp;
}

Tree parent(Tree t) {
    Tree temp;

    if(t == NULL) printf("No Parent Tree");
    else temp = t->parent;

    return temp;
}

Value value(Tree t) {
    Value vtemp = errorvalue;
    if (t == NULL) printf("Baum hat ein Errorvalue\n");
    else vtemp = t->v;

    return vtemp;
}

Tree insert(Value v, Tree t) {
    if (t == NULL) return cons(v, NULL, NULL);
    else if (t->left == NULL) {
        t->left = insert(v, t->left);
    }
    else if (t->right == NULL) {
        t->right = insert(v, t->right);
    }
    else {
        if (sizeTree(t->left) < sizeTree(t->right)) t->left = insert(v, t->left);
        else t->right = insert(v, t->right);
    }
    return t;
}

int sizeTree(Tree t) {
    int size = 0;
    if (t == NULL) size = 0;
    else size = 1 + sizeTree(t->left) + sizeTree(t->right);
    return size;
}

void inorder(Tree t, int level, VProc f) {
    if(t) {
        inorder(t->left, level+1, f);
        (*f)(t->v, level);
        inorder(t->right, level+1, f);
    }
}