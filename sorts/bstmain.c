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
    bst_insertIter(tree, -4);
    bst_insertIter(tree, -3);
    bst_insertIter(tree, -5);
    bst_insertIter(tree, -8);
    bst_insertIter(tree, -6);
    bst_insertIter(tree, -7);

    // bst_printPreOrder(tree);
    bst_printInOrder(tree);
    //bst_printAfterOrder(tree);

    if (bst_searchIter(tree, 3)) {
        printf("ye\n");
    } else {
        printf("nah\n");
    }

    bst_destroy(tree);

    return 0;
}