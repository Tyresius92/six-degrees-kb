/**********************************************************************
 * hashtable.h                                                        *
 *                                                                    *
 * Interface for a hashtable of which stores strings. Implementation  *
 * requires the client to input the expected size needed allocating   *
 * the hashtable. Implementation requires client to manage key-value  *
 * relationship. Both key and value must be of type string.           *
 **********************************************************************/

/***************************
 * PREPROCESSOR DIRECTIVES *
 ***************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

/*** INCLUDED FILES ***/

#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*** DEFINITIONS AND TYPEDEFS ***/

typedef struct DataItem {
        char * key; 
        char * value;
} DataItem;

typedef struct hashtable *Hashtable_t;

/**********************
 * FUNCTION CONTRACTS *
 * AND DECLARATIONS   *
 **********************/

/*
 * alloc_hashtable
 * 
 * allocates a hashtable of strings of size num_elems
 * initializes all values to NULL
 * 
 * CREs         num_elems < 0
 * 
 * UREs         System out of memory
 * 
 * @param       num_elems - the number of key-value pairs to be stored
 * @return      Hashtable_t - pointer to an array of char* (strings)
 */
Hashtable_t alloc_hashtable(unsigned num_elems); 

/*
 * hashtable_size
 * 
 * returns the number of elements currently in the hashtable
 */
unsigned hashtable_size(Hashtable_t table); 

/*
 * insert_item
 * 
 * given a key-value pair (both must be strings), stores the value
 * in the hashtable. 
 *
 * CREs         key == NULL
 * UREs         attempting to store the same key twice will result in
 *              undefined behavior
 * 
 * @param       char* - key of the value to be stored
 * @param       char* - value to be stored
 * @return      n/a
 */
void insert_item(Hashtable_t table, char* key, char* value);

/* 
 * get_value_at
 * 
 * given a key, returns the value at that key
 * if the key is not stored in the table, return NULL
 * 
 * CREs         key == NULL
 * UREs         n/a
 * 
 * @param       char* - the key value to find
 * @return      DataItem - struct containing the key and value
 */
DataItem get_DataItem_with_key(Hashtable_t table, char* key); 

/*
 * dealloc_hashtable 
 * 
 * deallocates the given hashtable
 * 
 * CREs         table == NULL
 * UREs         n/a
 * 
 * @param       Hashtable_t - the table to be deallocated
 * @return      n/a
 */
void dealloc_hashtable(Hashtable_t table); 

#endif