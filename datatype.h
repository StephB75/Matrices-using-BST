#ifndef DATATYPE_H
#define DATATYPE_H
#include <stdlib.h>
#include <string.h>
/**
 * sbian23
 * 251287906
 * cs2211
 * Kaizhong Zhang
 * December 4, 2023
 * This class defines the data structures for the data and key of the binary search tree
 */
typedef char *Key1;
typedef int Key2;
typedef struct
{
    Key1 key1;
    Key2 key2;
} key_object;

typedef key_object *Key;
typedef float *Data;

Key key_ini(void);
void key_set(Key key, Key1 key1, Key2 key2);
int key_comp(Key key1, Key key2);
void key_print1(Key key);
void key_print2(Key key);
void key_free(Key key);

Data data_ini(void);
void data_set(Data data, float value);
void data_print(Data data);
void data_free(Data data);

#endif /* DATATYPE_H */