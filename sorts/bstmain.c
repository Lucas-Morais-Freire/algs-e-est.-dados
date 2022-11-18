#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main() {
    struct bstree* tree = bst_inicialize();
    bst_insertRec(tree, 0);
    bst_insertRec(tree, 2);
    bst_insertRec(tree, 1);
    bst_insertRec(tree, 3);
    bst_insertRec(tree, -1);
    bst_insertRec(tree, -2);

    bst_destroy(tree);

    return 0;
}