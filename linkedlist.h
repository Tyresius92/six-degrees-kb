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
        void * data; 
        struct ListNode * next;
} ListNode;

typedef struct linkedlist *List_t;

/**********************
 * FUNCTION CONTRACTS *
 * AND DECLARATIONS   *
 **********************/


#endif