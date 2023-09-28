#include <stdio.h>
#include <stdlib.h>
#include "bstavl.h"
#include <time.h>

int main() {
    srand(time(NULL));
    struct bstavl* tree = avl_inicialize();
    for (int i = 0; i < 300;) {
        int n = rand() % 200 - 100;
        if (!avl_searchIter(tree, n)) {
            avl_insert(n, tree);
            i++;
        } else {
            printf("took\n");
            avl_remove(n, tree);
            i++;
        }
    }

    avl_prettierPrint(tree, 7);

    avl_destroy(tree);

    return 0;
}