#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>

struct bstnode {
    int val;
    struct bstnode* r;
    struct bstnode* l;
};

struct bstree {
    int n;
    struct bstnode* root;
};

struct bstree* bst_inicialize() {
    struct bstree* tree = (struct bstree*)malloc(sizeof(struct bstree));
    tree->n = 0;
    tree->root = NULL;
    return tree;
}

struct bstnode* bst_newNode(int value) {
    struct bstnode* newNode = (struct bstnode*)malloc(sizeof(struct bstnode));
    newNode->r = NULL;
    newNode->l = NULL;
    newNode->val = value;
    return newNode;
}

void bst_insertRec(struct bstnode** root, struct bstnode* node) {
    if ((*root) == NULL) {
        root = &(node);
        return;
    }

    if ()
}

#endif //BINTREE_H