/**********************************************************************
 * linkedlist.h                                                       *
 *                                                                    *
 * interface of a linked list                                         *
 * implementation only supports insertion and clearing the entire     * 
 * list. functionality for sorting, deleting single nodes, etc. does  * 
 * not exist.                                                         *
 **********************************************************************/

/***************************
 * PREPROCESSOR DIRECTIVES *
 ***************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*** INCLUDED FILES ***/

#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*** DEFINITIONS AND TYPEDEFS ***/

typedef struct linkedlist *List_t;

/**********************
 * FUNCTION CONTRACTS *
 * AND DECLARATIONS   *
 **********************/

/*
 * List_new
 * 
 * Allocates a new, empty list, in which the head points to NULL
 * 
 * CREs         n/a
 * UREs         out of memory
 * 
 * @return      List_t
 */
List_t List_new(); 

/* 
 * List_length
 * 
 * returns the current length of a given list
 * 
 * CREs         list == NULL
 * UREs         n/a
 * 
 * @param       List_t - list to get length of
 * @return      int - length of list
 */
int List_length(List_t list); 

/*
 * get_string
 * 
 * gets the string in the node indicated by node_num. 
 * uses a 0 index system. If node_num >= list->length, returns NULL
 * 
 * CREs         list == NULL
 * UREs         n/a
 * 
 * @param       List_t - list being searched
 * @param       int - "index" of the node to get a string from
 * @return      char *
 */ 
char *get_string(List_t list, int node_num); 

/*
 * insert_front
 * 
 * inserts the given string at the front of the list
 * 
 * CREs         list == NULL
 * UREs         if new_node->next points to something, it will be lost
 *                      after this function is called
 * 
 * @param       List_t - list into which the node is being inserted
 * @param       char* - node to be inserted
 * @return      n/a
 */ 
void insert_front(List_t list, char* new_string);

/*
 * List_clear
 * 
 * deallocates everything held in the list, sets head to NULL
 * 
 * CREs	        list == NULL
 * UREs         n/a
 * 
 * @param       List_t - List to be cleared
 * @return      n/a
 */
void List_clear(List_t list); 

/*
 * List_destroy
 *
 * clears the list, then deallocates the list
 *
 * CREs         list == NULL
 * UREs         n/a
 * 
 * @param       List_t - list to be destroyed
 * @return      n/a
 */
void List_destroy(List_t list); 

#endif