/**********************************************************************
 * linkedlist.h                                                       *
 *                                                                    *
 *                                                                    *
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

typedef struct ListNode {
        char *data; 
        struct ListNode *next;
} ListNode;

typedef struct linkedlist *List_t;

/**********************
 * FUNCTION CONTRACTS *
 * AND DECLARATIONS   *
 **********************/

/*
 * List_new
 * 
 * Allocates a new, empty list, in which the head just points to NULL
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
 * get_first_node
 * 
 * returns the first node in the List_t
 * once you have the first node, you can get each successive node 
 * The last node of any List_t will point to NULL
 */ 
ListNode get_first_node(List_t list); 

/*
 * insert_front
 * 
 * inserts the given ListNode at the front of the list
 * 
 * CREs         list == NULL
 * UREs         n/a
 * 
 * @param       List_t - list into which the node is being inserted
 * @param       ListNode - node to be inserted
 * @return      n/a
 */ 
void insert_front(List_t list, ListNode new_node);

/*
 * List_clear
 * 
 * deallocates every ListNode held in the list, sets head to NULL
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
 * deallocates every ListNode held in the list, then deallocates List
 *
 * CREs         list == NULL
 * UREs         n/a
 * 
 * @param       List_t - list to be destroyed
 * @return      n/a
 */
void List_destroy(List_t list); 

#endif