/**********************************************************************
 * linkedlist.c                                                       *
 *                                                                    *
 *                                                                    *
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


List_t List_new()
{

}

int List_length(List_t list)
{
        (void) list; 
        return 0; 
}

void insert_front(List_t list, ListNode new_node)
{
        (void) list; 
        (void) new_node; 
}

void List_clear(List_t list)
{
        (void) list; 
}

void List_destroy(List_t list)
{
        (void) list; 
}