#ifndef BSTAVL_H
#define BSTAVL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool printedFirst = false;

struct avlnode {
    int val;
    struct avlnode* r;
    struct avlnode* l;
    int bf;
    int h;
};

struct bstavl {
    int size;
    struct avlnode* root;
};

struct bstavl* avl_inicialize() {
    struct bstavl* tree = (struct bstavl*)malloc(sizeof(struct bstavl));
    tree->size = 0;
    tree->root = NULL;
    return tree;
}

struct avlnode* avl_newNode(int value) {
    struct avlnode* newNode = (struct avlnode*)malloc(sizeof(struct avlnode));
    newNode->r = NULL;
    newNode->l = NULL;
    newNode->h = 0;
    newNode->bf = 0;
    newNode->val = value;
    return newNode;
}

int avl_heightFromNode(struct avlnode* node) {
    if (node->l == NULL && node->r == NULL) {
        return 0;
    } else if (node->l != NULL && node->r == NULL) {
        return node->l->h + 1;
    } else if (node->l == NULL && node->r != NULL) {
        return node->r->h + 1;
    } else if (node->r->h >= node->l->h) {
        return node->r->h + 1;
    } else {
        return node->l->h + 1;
    }
}

int avl_height(struct bstavl* tree) {
    return avl_heightFromNode(tree->root);
}

void avl_update(struct avlnode* node) {
    node->h = avl_heightFromNode(node);
    if (node->l == NULL && node->r == NULL) {
        node->bf = 0;
    } else if (node->l != NULL && node->r == NULL) {
        node->bf = -node->l->h;
    } else if (node->l == NULL && node->r != NULL) {
        node->bf = node->r->h;
    } else {
        node->bf = node->r->h - node->l->h;
    }
}

struct avlnode* avl_rotLeft(struct avlnode* node) {
    struct avlnode* newRoot = node->r;
    node->r = newRoot->l;
    newRoot->l = node;
    avl_update(node);
    avl_update(newRoot);
    return newRoot;
}

struct avlnode* avl_rotRight(struct avlnode* node) {
    struct avlnode* newRoot = node->l;
    node->l = newRoot->r;
    newRoot->r = node;
    avl_update(node);
    avl_update(newRoot);
    return newRoot;
}

struct avlnode* avl_rebalanceLL(struct avlnode* node) {
    return avl_rotRight(node);
}

struct avlnode* avl_rebalanceLR(struct avlnode* node) {
    node->l = avl_rotLeft(node->l);
    return avl_rotRight(node);
}

struct avlnode* avl_rebalanceRR(struct avlnode* node) {
    return avl_rotLeft(node);
}

struct avlnode* avl_rebalanceRL(struct avlnode* node) {
    node->r = avl_rotRight(node->l);
    return avl_rotLeft(node);
}

struct avlnode* avl_rebalance(struct avlnode* node) {
    if (node->bf == 2 && node->r->bf == -1) {
        return avl_rebalanceRL(node);
    } else if (node->bf == 2) {
        return avl_rebalanceRR(node);
    } else if (node->bf == -2 && node->l->bf == 1) {
        return avl_rebalanceLR(node);
    } else if (node->bf == -2) {
        return avl_rebalanceLL(node);
    }
    return node;
}

void avl_insertNode(struct avlnode* node, struct avlnode** pToRoot) {
    if ((*pToRoot) == NULL) {
        (*pToRoot) = node;
    } else {
        if (node->val >= (*pToRoot)->val) {
            if ((*pToRoot)->r == NULL) {
                (*pToRoot)->r = node;
            } else {
                avl_insertNode(node, &((*pToRoot)->r));
            }
        } else {
            if ((*pToRoot)->l == NULL) {
                (*pToRoot)->l = node;
            } else {
                avl_insertNode(node, &((*pToRoot)->l));
            }
        }
    }

    avl_update((*pToRoot));
    (*pToRoot) = avl_rebalance((*pToRoot));
}

void avl_insert(int value, struct bstavl* tree) {
    struct avlnode* newNode = avl_newNode(value);
    avl_insertNode(newNode, &(tree->root));
    tree->size++;
}

bool avl_searchFromRootRec(struct avlnode* root, int value) {
    if (root->val == value) {
        return true;
    } else if (root->r != NULL && value >= root->val) {
        return avl_searchFromRootRec(root->r, value);
    } else if (root->l != NULL && value < root->val) {
        return avl_searchFromRootRec(root->l, value);
    } else {
        return false;
    }
}

bool avl_searchRec(struct bstavl* tree, int value) {
    struct avlnode* root = tree->root;
    return avl_searchFromRootRec(root, value);
}

bool avl_searchFromRootIter(struct avlnode* root, int value) {
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

bool avl_searchIter(struct bstavl* tree, int value) {
    struct avlnode* root = tree->root;
    return avl_searchFromRootIter(root, value);
}

int avl_minFromRoot(struct avlnode* root) {
    if (root->l == NULL) {
        return root->val;
    }
    return avl_minFromRoot(root->l);
}

int avl_min(struct bstavl* tree) {
    return avl_minFromRoot(tree->root);
}

int avl_maxFromRoot(struct avlnode* root) {
    if (root->r == NULL) {
        return root->val;
    }
    return avl_maxFromRoot(root->r);
}

int avl_max(struct bstavl* tree) {
    return avl_maxFromRoot(tree->root);
}

struct avlnode* avl_removeFromNode(int value, struct avlnode* node) {
    struct avlnode* aux = NULL;
    if (node->val == value) {
        if (node->l != NULL && node->r == NULL) {
            aux = node->l;
        } else if (node->l == NULL && node->r != NULL) {
            aux = node->r;
        } else if (node->l != NULL && node->r != NULL) {
            aux = avl_newNode(avl_minFromRoot(node->r));
            aux->r = avl_removeFromNode(aux->val, node->r);
            aux->l = node->l;
            avl_update(aux);
            aux = avl_rebalance(aux);
        }
        free(node);
        return aux;
    } else if (node->val < value) {
        node->r = avl_removeFromNode(value, node->r);
        avl_update(node);
        node = avl_rebalance(node);
        return node;
    } else {
        node->l = avl_removeFromNode(value, node->l);
        avl_update(node);
        node = avl_rebalance(node);
        return node;
    }
}

void avl_remove(int value, struct bstavl* tree) {
    tree->root = avl_removeFromNode(value, tree->root);
    tree->size--;
}

void avl_printPreOrderFromNode(struct avlnode* node) {
    if (node != NULL) {
        if (!printedFirst) {
            printf("%d", node->val);
            printedFirst = true;
        } else {
            printf(", %d", node->val);
        }
        avl_printPreOrderFromNode(node->l);
        avl_printPreOrderFromNode(node->r);
    }
}

void avl_printPreOrder(struct bstavl* tree) {
    avl_printPreOrderFromNode(tree->root);
    printedFirst = false;
    printf("\n");
}

void avl_printInOrderFromNode(struct avlnode* node) {
    if (node != NULL) {
        avl_printInOrderFromNode(node->l);
        if (!printedFirst) {
            printf("%d", node->val);
            printedFirst = true;
        } else {
            printf(", %d", node->val);
        }
        avl_printInOrderFromNode(node->r);
    }
}

void avl_printInOrder(struct bstavl* tree) {
    avl_printInOrderFromNode(tree->root);
    printedFirst = false;
    printf("\n");
}

void avl_printAfterOrderFromNode(struct avlnode* node) {
    if (node != NULL) {
        avl_printAfterOrderFromNode(node->l);
        avl_printAfterOrderFromNode(node->r);
        if (!printedFirst) {
            printf("%d", node->val);
            printedFirst = true;
        } else {
            printf(", %d", node->val);
        }
    }
}

void avl_printAfterOrder(struct bstavl* tree) {
    avl_printAfterOrderFromNode(tree->root);
    printedFirst = false;
    printf("\n");
}

void avl_prettyPrintFromNode(struct avlnode* node, int ind) {
    if(node != NULL) {
        if(node->l) avl_prettyPrintFromNode(node->l, ind+4);
        if(node->r) avl_prettyPrintFromNode(node->r, ind+4);
        if (ind) {
            for (int i = 0; i < ind; i++) {
                printf(" ");
            }
        }
        printf("%d(%d)(%d)\n ", node->val, node->h, node->bf);
    }
}

void avl_prettyPrint(struct bstavl* tree) {
    avl_prettyPrintFromNode(tree->root, 0);
}

void avl_destroyFromRoot(struct avlnode* root) {
    if (root->l != NULL) {
        avl_destroyFromRoot(root->l);
    }
    if (root->r != NULL) {
        avl_destroyFromRoot(root->r);
    }
    free(root);
}

void avl_destroy(struct bstavl* tree) {
    avl_destroyFromRoot(tree->root);
    free(tree);
}

#endif //BSTAVL_H