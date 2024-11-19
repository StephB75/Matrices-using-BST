#ifndef BSTREE_H
#define BSTREE_H
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

/**
 * sbian23
 * 251287906
 * cs2211
 * Kaizhong Zhang
 * December 4, 2023
 * This class defines the data structures for a binary search tree
 */

typedef struct BStree_node
{
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;

// Define BStree as a pointer to a pointer to a BStree_node
typedef BStree_node **BStree;

BStree bstree_ini(void);

void bstree_insert(BStree bst, Key key, Data data);

Data bstree_search(BStree bst, Key key);

void bstree_traverse(BStree bst);

void bstree_free(BStree bst);

#endif /* BSTREE_H */