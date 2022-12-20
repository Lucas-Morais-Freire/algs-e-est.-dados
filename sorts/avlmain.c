#include <stdio.h>
#include <stdlib.h>
#include "bstavl.h"

int main() {
    struct bstavl* tree = avl_inicialize();
    for (int i = 15; i >= -15; i--) {
        avl_insert(i, tree);
    }
    avl_prettierPrint(tree, 9);

    avl_destroy(tree);

    return 0;
}