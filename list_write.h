/**********************************************************************
 * list_write.c                                                       *
 *                                                                    *
 * given IMDB's files name.basics.tsv, title.basics.tsv, and          *
 * title.principals.tsv, reads in and stores the basics files into    * 
 * separate hashtables, then reads the principals file and writes a   * 
 * new file which combines these lists, filtering to only movies in   * 
 * the process.                                                       * 
 **********************************************************************/

/***************************
 * PREPROCESSOR DIRECTIVES *
 ***************************/

#ifndef LIST_WRITE_H
#define LIST_WRITE_H

/*** INCLUDED FILES ***/

#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "hashtable.h"

/*** DEFINITIONS AND TYPEDEFS ***/



/**********************
 * FUNCTION CONTRACTS *
 * AND DECLARATIONS   *
 **********************/

/* 
 * read_actor_file
 * 
 * reads actor file, parses it, and stores the associated key value
 * pairs, and returns the Hashtable
 * 
 * CREs
 * UREs
 * 
 * @param       FILE * - pointer to an open file
 * @return      Hashtable_t
 */ 
Hashtable_t read_actor_file(FILE *actor_file); 

/*
 * read_movie_file
 * 
 * CREs
 * UREs
 * 
 * @param       FILE * - pointer to an open file
 * @return      Hashtable_t
 */ 
Hashtable_t read_movie_file(FILE *movie_file); 

/* 
 * write_combined_file
 * 
 * CREs
 * UREs
 * 
 * @param       FILE * - pointer to an open file title.principals.tsv
 * @param       Hashtable_t - hashtable containing actor data
 * @param       Hashtable_t - hashtable containing movie data
 * @return      n/a
 */ 
void write_combined_file(FILE *roles_file, Hashtable_t actor_table, 
                         Hashtable_t movie_table); 

void 

#endif