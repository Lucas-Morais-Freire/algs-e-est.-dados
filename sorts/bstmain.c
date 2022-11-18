#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main() {
    struct bstree* tree = bst_inicialize();
    bst_insertIter(tree, 0);
    bst_insertIter(tree, 2);
    bst_insertIter(tree, 1);
    bst_insertIter(tree, 3);
    bst_insertIter(tree, -1);
    bst_insertIter(tree, -2);

    bst_destroy(tree);

    return 0;
}