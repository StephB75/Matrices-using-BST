
#include "datatype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * sbian23
 * 251287906
 * cs2211
 * Kaizhong Zhang
 * December 4, 2023
 *
 * This class represents the data that is going to be stored in a node object.
 */

// constructor for the key data object
Key key_ini(void)
{
    // creates a new key allocating memory to it
    Key k = (Key)malloc(sizeof(key_object));

    // set the second key to 0
    k->key2 = 0;
    // set the first key to null
    k->key1 = NULL;
    // return the key
    return k;
}

/**
 * sets the key objects key1 and key2 to the given key1 and key2 in the parameters
 */
void key_set(Key key, Key1 key1, Key2 key2)
{
    // if key is not null
    if (key != NULL)
    {
        // set key1 and key2 to the ones in the parameters
        key->key1 = strdup(key1);
        key->key2 = key2;
    }
}

/**
 * this is the comparator class that compares the 2 keys
 */
int key_comp(Key k1, Key k2)
{
    if (k1 == NULL || k2 == NULL)
    {
        return 0;
    }
    else
    {
        int comparor = strcmp(k1->key1, k2->key1);
        if (comparor != 0)
        {
            return comparor;
        }
        else if (comparor == 0)
        {
            return k1->key2 - k2->key2;
        }
    }
    return 0;
}

/**
 * prints the first key
 */
void key_print1(Key key)
{
    // if the key is not null and the key1 is not null
    if (key != NULL)
    {
        // print key2, key1
        printf("%d %s ", key->key2, key->key1);
    }
}

/**
 * prints the second key
 */
void key_print2(Key key)
{
    // if the key is not null and the key2 is not null
    if (key != NULL)
    {
        // print the key2 and key1
        printf("(%d, %s)\n", key->key2, key->key1);
    }
}

/**
 * frees the key
 */
void key_free(Key key)
{
    // if the key is null return
    if (key == NULL)
    {
        return;
    }
    // else free the key1 and key
    else
    {
        free(key->key1);
        free(key);
    }
}

/**
 * data constructor, creates a new data object
 */
Data data_ini(void)
{
    // allocates memory for the data object
    Data d = (Data)malloc(sizeof(float));
    // set it to 0
    *d = 0.0;
    return d;
}

/**
 * sets the data to the float given through the parameters
 */
void data_set(Data data, float intdata)
{
    // set data to int data
    *data = intdata;
}

/**
 * prints the data inside the object
 */
void data_print(Data data)
{
    // if the data is not null
    if (data != NULL)
    {
        // print data
        printf("%f\n", *data);
    }
    // tell the user that there is no data
    else
    {
        printf("no data to print \n");
    }
}

/**
 * free the data
 */
void data_free(Data data)
{
    // if the data is not null already
    if (data != NULL)
    {
        // free the data
        free(data);
    }
}