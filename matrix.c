
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sbian23
 * 251287906
 * cs2211
 * Kaizhong Zhang
 * December 4, 2023
 *
 * This class represents a tree matrix using the bstree.c class
 */

/**
 * constructor for matrix
 * returns the binary search tree initializer
 */
Matrix matrix_construction(void)
{
    return bstree_ini();
}

/**
 *if the location of the indexes given through the parameters is defined in matrix m, the method returns 1, otherwise it returns 0
 */
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2)
{
    // creates a key
    Key k = key_ini();
    // set the key to whatever is put through index1 and index2
    key_set(k, index1, index2);

    // create a new data object equal to whatever is found using the binary search tree search
    Data data = bstree_search(m, k);
    // free the key
    key_free(k);

    // return null if data is not null (something is found)
    if (data != NULL)
    {
        return 1;
    }
    // return 0 if data is null (something was not found)
    else
    {
        return 0;
    }
}

/**
 * if location given through the parameters index1 and index2 is defined in matrix m, it returns the pointer to the node
 */
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2)
{
    // create new key
    Key k = key_ini();
    // set the key given the indexes
    key_set(k, index1, index2);
    // create new data using the key and matrix
    Data d = bstree_search(m, k);

    // cast data pointer to a pointer value
    const Value *v = (const Value *)d;
    // free key
    key_free(k);
    // return value
    return v;
}

/**
 * assigns value to matrix m given the location of indexes
 * Furthermore, it overwrites the existing one if it already has a value
 */
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value)
{
    // create key
    Key k = key_ini();
    // set the key given the index
    key_set(k, index1, index2);
    // creates new data object allocating it memory size of value
    Data d = malloc(sizeof(Value));
    // if the data is null stop

    // data pointer set to value
    *d = value;
    // insert the key and data
    bstree_insert(m, k, d);
}

/**
 * uses the bstree_traverse to list the contents of the matrix
 */
void matrix_list(Matrix m)
{
    bstree_traverse(m);
}

/**
 * uses the bstree_free method to free all the nodes of the tree destroying the matrix
 */
void matrix_destruction(Matrix m)
{
    bstree_free(m);
}