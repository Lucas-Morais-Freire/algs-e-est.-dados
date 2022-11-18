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
    int size;
    struct bstnode* root;
};

struct bstree* bst_inicialize() {
    struct bstree* tree = (struct bstree*)malloc(sizeof(struct bstree));
    tree->size = 0;
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

void bst_insertNodeRec(struct bstnode** pToRoot, struct bstnode* node) {
    if ((*pToRoot) == NULL) {
        (*pToRoot) = node;
    } else {
        if (node->val >= (*pToRoot)->val) {
            if ((*pToRoot)->r == NULL) {
                (*pToRoot)->r = node;
            } else {
                bst_insertNodeRec(&((*pToRoot)->r), node);
            }
        } else {
            if ((*pToRoot)->l == NULL) {
                (*pToRoot)->l = node;
            } else {
                bst_insertNodeRec(&((*pToRoot)->l), node);
            }
        }
    }
}

void bst_insertRec(struct bstree* tree, int value) {
    struct bstnode* newNode = bst_newNode(value);
    bst_insertNodeRec(&(tree->root), newNode);
    tree->size++;
}

void bst_insertNodeIter(struct bstnode** pToRoot, struct bstnode* node) {
    if ((*pToRoot) == NULL) {
        (*pToRoot) = node;
    } else {
        struct bstnode** aux = pToRoot;
        while(1) {
            if (node->val >= (*aux)->val) {
                if ((*aux)->r == NULL) {
                    (*aux)->r = node;
                    break;
                } else {
                    aux = &((*aux)->r);
                }
            } else {
                if ((*aux)->l == NULL) {
                    (*aux)->l = node;
                    break;
                } else {
                    aux = &((*aux)->l);
                }
            }
        }
    }
}

void bst_insertIter(struct bstree* tree, int value) {
    struct bstnode* newNode = bst_newNode(value);
    bst_insertNodeIter(&(tree->root), newNode);
    tree->size++;
}

void bst_destroyFromRoot(struct bstnode* root) {
    if (root->l != NULL) {
        bst_destroyFromRoot(root->l);
    }
    if (root->r != NULL) {
        bst_destroyFromRoot(root->r);
    }
    free(root);
}

void bst_destroy(struct bstree* tree) {
    bst_destroyFromRoot(tree->root);
    free(tree);
}

#endif //BINTREE_H