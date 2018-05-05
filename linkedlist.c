/**********************************************************************
 * linkedlist.c                                                       *
 *                                                                    *
 * implementation of a linked list                                    *
 * implementation only supports insertion and clearing the entire     * 
 * list. functionality for sorting, deleting single nodes, etc. does  * 
 * not exist.                                                         *
 **********************************************************************/

/***************************
 * PREPROCESSOR DIRECTIVES *
 ***************************/

#include "linkedlist.h"

/*********************
 * MACRO DEFINITIONS *
 *********************/



/********************
 * STATIC VARIABLES *
 ********************/


/******************************
 * LINKED LIST REPRESENTATION *
 ******************************/

struct linkedlist {
        int length; 
        ListNode * head;
}; 

typedef List_t T;

/*******************************
 * PRIVATE METHOD DECLARATIONS *
 *******************************/



/************************
 * FUNCTION DEFINITIONS *
 ************************/


T List_new()
{
        T new_list = malloc(sizeof(struct linkedlist)); 

        new_list->length = 0; 
        new_list->head = NULL; 

        return new_list; 
}

int List_length(T list)
{
        assert(list != NULL); 

        return list->length; 
}

ListNode *get_first_node(List_t list)
{
        assert(list != NULL); 

        return list->head; 
}

void insert_front(T list, ListNode new_node)
{
        (void) list; 
        (void) new_node; 
}

void List_clear(T list)
{
        (void) list; 
}

void List_destroy(T list)
{
        (void) list; 
}