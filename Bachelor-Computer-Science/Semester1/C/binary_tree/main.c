#include <stdio.h>
#include "binary_tree.h"

void show(Value v, int level) { printf("%d: %d\n", v, level); }

int main() {
    char c = 'a';
    int i;
    Tree t = NULL;
    
    while(c != EOF) {
        c = getchar();
        if (c != ' ' && c != EOF) {
            i = (int)c;
            t = insert((i-48), t);
        }
    }

    inorder(t, 0, show);

    return 0;
}
