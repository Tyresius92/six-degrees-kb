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


/***************************
 * LISTNODE REPRESENTATION *
 ***************************/

typedef struct ListNode {
        char *data; 
        struct ListNode *next;
} ListNode;

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

char *get_string(List_t list, int node_num)
{
        assert(list != NULL); 

        if (node_num >= list->length) {
                return NULL; 
        }

        ListNode *curr = list->head; 

        for (int i = 0; i < node_num; i++) {
                curr = curr->next; 
        }

        return curr->data;  
}

void insert_front(T list, char *new_string) 
{
        assert(list != NULL); 

        ListNode *new_node = malloc(sizeof(ListNode)); 

        new_node->data = new_string; 

        new_node->next = list->head; 
        list->head = new_node;

        list->length = list->length + 1;  
}

void List_clear(T list)
{
        assert(list != NULL); 

        ListNode *delete_me = list->head; 

        while (delete_me != NULL) {
                ListNode *next_node = delete_me->next; 
                free(delete_me); 
                delete_me = next_node;
        }

        list->head = NULL; 
}

void List_destroy(T list)
{
        List_clear(list); 

        free(list); 
        list = NULL; 
}