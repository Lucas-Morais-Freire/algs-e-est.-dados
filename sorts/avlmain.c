#include <stdio.h>
#include <stdlib.h>
#include "bstavl.h"

int main() {
    struct bstavl* tree = avl_inicialize();
    avl_insertIter(tree, 0);
    avl_insertIter(tree, -2);
    avl_insertIter(tree, -7);
    avl_insertIter(tree, -8);
    avl_insertIter(tree, -10);
    avl_insertIter(tree, -11);
    avl_insertIter(tree, -1);
    avl_insertIter(tree, -5);
    avl_insertIter(tree, -6);
    avl_insertIter(tree, -4);
    avl_insertIter(tree, -3);
    avl_insertIter(tree, -9);

    avl_prettyPrint(tree);

    avl_remove(-7, tree);

    avl_prettyPrint(tree);

    avl_destroy(tree);

    return 0;
}