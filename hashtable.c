/**********************************************************************
 * hashtable.c                                                        *
 *                                                                    *
 * Implementation for a hashtable of which stores strings. Requires 
 * the client to input the expected size needed when allocating       *
 * the hashtable. Implementation requires client to manage key-value  *
 * relationship. Both key and value must be of type string.           *
 **********************************************************************/

/***************************
 * PREPROCESSOR DIRECTIVES *
 ***************************/

#include "hashtable.h"
//#define Hashtable_t *struct DataItem;

/*************************
 * DataItem REPRESENTION *
 *************************/



/************************
 * FUNCTION DEFINITIONS *
 ************************/

Hashtable_t alloc_hashtable(int num_elems)
{
        int size = sizeof(struct DataItem) * num_elems; 

        Hashtable_t newTable = malloc(size); 

        return newTable; 
}

void insert_item(char* key, char* value)
{
        (void) key; 
        (void) value; 
}

DataItem get_value_at(char* key)
{
        (void) key; 
        return NULL; 
}

void dealloc_hashtable(Hashtable_t table)
{
        (void) table; 
}