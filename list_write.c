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

#include "hashtable.h"

/*********************
 * MACRO DEFINITIONS *
 *********************/



/********************
 * STATIC VARIABLES *
 ********************/