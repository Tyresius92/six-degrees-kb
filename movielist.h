#include "hashtable.h"
#include "linkedlist.h"

/*
 * generate_movie_hashtable
 * 
 * generates a hashtable from the title.basics.tsv file 
 * downloaded from IMDB. file path is hard coded into this function. 
 * Hashtable key is the 
 * 
 * CREs         file fails to open
 * UREs         Out of memory
 * 
 * @return      Hashtable_t
 */ 
Hashtable_t generate_movie_hashtable(); 

/*
 * generate_actor_hashtable
 * 
 * generates a hashtable from the name.basics.tsv file 
 * downloaded from IMDB. file path is hard coded into this function
 * 
 * CREs         file fails to open
 * UREs         Out of memory
 * 
 * @return      Hashtable_t
 */ 
Hashtable_t generate_actor_hashtable();

/*
 * generate_merged_table
 */
Hashtable_t generate_merged_table(Hashtable_t actors, Hashtable_t movies); 
