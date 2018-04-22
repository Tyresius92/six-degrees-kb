/**********************************************************************
 * hashtable.c                                                        *
 *                                                                    *
 * Implementation for a hashtable of which stores strings. Requires 
 * the client to input the expected size needed when allocating       *
 * the hashtable. Implementation requires client to manage key-value  *
 * relationship. Both key and value must be of type string.           *
 **********************************************************************/

/***************************
 * PREPROCESSOR DIRECTIVES *
 ***************************/

#include "hashtable.h"

/*********************
 * MACRO DEFINITIONS *
 *********************/

#define NELEMS(A) (sizeof(A) / sizeof((A)[0]))

/********************
 * STATIC VARIABLES *
 ********************/

static const unsigned list_of_primes[] = { 3, 7, 17, 31, 127, 709, 5381, 52711, 
                                           648379, 999959, 5034937, 9736927, 
                                           15387793, 20843569, 26326043,
                                           43467679, 49979323, 59620331 };

static const struct DataItem Empty_Struct = { NULL, NULL };

//typedef struct hashtable *Hashtable_t;

struct hashtable {
        unsigned table_size;  
        unsigned elements_stored; 
        DataItem *array; 
}; 


/*******************************
 * PRIVATE METHOD DECLARATIONS *
 *******************************/

static unsigned determine_table_size(unsigned num_elems); 

static unsigned long hash(unsigned char* key); 

/************************
 * FUNCTION DEFINITIONS *
 ************************/

Hashtable_t alloc_hashtable(unsigned num_elems)
{ 
        Hashtable_t newTable = malloc(sizeof(struct hashtable)); 

        newTable->table_size = determine_table_size(num_elems);

        newTable->array = calloc(newTable->table_size, sizeof(struct DataItem)); 
        
        //debug
        fprintf(stderr, "Calloc was successful\n"); 
        
        for (unsigned i = 0; i < newTable->table_size; i++) {
                newTable->array[i] = Empty_Struct;
        }

        return newTable; 
}

static unsigned determine_table_size(unsigned num_elems)
{
        unsigned i, table_size; 

        for (i = 1; i < NELEMS(list_of_primes); i++) {
                if (num_elems * 2 < list_of_primes[i]) {
                        table_size = list_of_primes[i]; 
                        break;
                }
        }

        return table_size;
}

unsigned hashtable_size(Hashtable_t table)
{
        assert(table != NULL); 
        return table->table_size;
}

unsigned hashtable_elems(Hashtable_t table)
{
        assert(table != NULL); 
        return table->elements_stored; 
}

void insert_item(Hashtable_t table, char* key, char* value)
{
        assert(table != NULL); 
        assert(key != NULL); 

        table->elements_stored += 1; 
        if (table->elements_stored == table->table_size) { 
                fprintf(stderr, "Table is full, no room to insert.\n");
                fprintf(stderr, "Exiting.\n"); 
                exit(EXIT_FAILURE); 
        } 

        DataItem new_data; 
        unsigned long index = hash((unsigned char*) key) % table->table_size;

        //debug
        fprintf(stderr, "Table size: %d\n", table->table_size); 
        fprintf(stderr, "index: %ld\n", index); 

        new_data.key = key; 
        new_data.value = value; 

        while(table->array[index].key != NULL) {
                index++; 
                if (index == table->table_size)
                        index = 0; 
        }

        table->array[index] = new_data; 

}

static unsigned long hash(unsigned char *key)
{
        /* djb2 algorithm */
        unsigned long hash = 5381;
        int c;

        while ((c = *key++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
}

DataItem get_DataItem_with_key(Hashtable_t table, char* key)
{
        assert(table != NULL); 
        assert(key != NULL); 

        DataItem stored_DataItem;
        unsigned long index = hash((unsigned char*) key) % table->table_size; 

        DataItem *tableArray = table->array; 

        while ((tableArray->key != NULL) && (tableArray->key != key)) {
                index++; 
        }

        stored_DataItem = table->array[index]; 

        return stored_DataItem; 
}

void dealloc_hashtable(Hashtable_t table)
{
        free(table->array);
        free(table);
        table = NULL; 
}