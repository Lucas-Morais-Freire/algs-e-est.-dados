#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool printedFirst = false;

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

bool bst_searchFromRootRec(struct bstnode* root, int value) {
    if (root->val == value) {
        return true;
    } else if (root->r != NULL && value >= root->val) {
        return bst_searchFromRootRec(root->r, value);
    } else if (root->l != NULL && value < root->val) {
        return bst_searchFromRootRec(root->l, value);
    } else {
        return false;
    }
}

bool bst_searchRec(struct bstree* tree, int value) {
    struct bstnode* root = tree->root;
    return bst_searchFromRootRec(root, value);
}

bool bst_searchFromRootIter(struct bstnode* root, int value) {
    while(1) {
        if (root->val == value) {
            return true;
        } else if (root->r != NULL && value >= root->val) {
            root = root->r;
        } else if (root->l != NULL && value < root->val) {
            root = root->l;
        } else {
            return false;
        }
    }
}

bool bst_searchIter(struct bstree* tree, int value) {
    struct bstnode* root = tree->root;
    return bst_searchFromRootIter(root, value);
}

int bst_minFromRoot(struct bstnode* root) {
    if (root->l == NULL) {
        return root->val;
    }
    return bst_minFromRoot(root->l);
}

int bst_min(struct bstree* tree) {
    return bst_minFromRoot(tree->root);
}

int bst_maxFromRoot(struct bstnode* root) {
    if (root->r == NULL) {
        return root->val;
    }
    return bst_maxFromRoot(root->r);
}

int bst_max(struct bstree* tree) {
    return bst_maxFromRoot(tree->root);
}

/* int bst_heightFromRoot(struct bstnode* root) {
    if (root->l != NULL) {
        return bst_heightFromRoot(root->l);
    }
    if (root->r != NULL) {
        return bst_heightFromRoot(root->r)
    }
    
}

int bst_height(struct bstree* tree) {
    int nIter = 0;
    return bst_heightFromRoot(tree->root);
} */

void bst_printPreOrderFromRoot(struct bstnode* root) {
    if (root != NULL) {
        if (!printedFirst) {
            printf("%d", root->val);
            printedFirst = true;
        } else {
            printf(", %d", root->val);
        }
        bst_printPreOrderFromRoot(root->l);
        bst_printPreOrderFromRoot(root->r);
    }
}

void bst_printPreOrder(struct bstree* tree) {
    bst_printPreOrderFromRoot(tree->root);
    printedFirst = false;
    printf("\n");
}

void bst_printInOrderFromRoot(struct bstnode* root) {
    if (root != NULL) {
        bst_printInOrderFromRoot(root->l);
        if (!printedFirst) {
            printf("%d", root->val);
            printedFirst = true;
        } else {
            printf(", %d", root->val);
        }
        bst_printInOrderFromRoot(root->r);
    }
}

void bst_printInOrder(struct bstree* tree) {
    bst_printInOrderFromRoot(tree->root);
    printedFirst = false;
    printf("\n");
}

void bst_printAfterOrderFromRoot(struct bstnode* root) {
    if (root != NULL) {
        bst_printAfterOrderFromRoot(root->l);
        bst_printAfterOrderFromRoot(root->r);
        if (!printedFirst) {
            printf("%d", root->val);
            printedFirst = true;
        } else {
            printf(", %d", root->val);
        }
    }
}

void bst_printAfterOrder(struct bstree* tree) {
    bst_printAfterOrderFromRoot(tree->root);
    printedFirst = false;
    printf("\n");
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