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

struct hashtable {
        unsigned table_size;
        unsigned elements_stored; 
        DataItem *array; 
}; 

typedef Hashtable_t T;

/*******************************
 * PRIVATE METHOD DECLARATIONS *
 *******************************/

static unsigned determine_table_size(unsigned num_elems); 
static void is_full_table(T table);
static unsigned long hash(unsigned char* key); 
static unsigned long adjust_index_linear_probe(T table, unsigned long index);

/************************
 * FUNCTION DEFINITIONS *
 ************************/

T alloc_hashtable(unsigned num_elems)
{ 
        T newTable = malloc(sizeof(struct hashtable)); 

        newTable->table_size = determine_table_size(num_elems);

        newTable->array = calloc(newTable->table_size, sizeof(struct DataItem));
        
        for (unsigned i = 0; i < newTable->table_size; i++) {
                newTable->array[i] = Empty_Struct;
        }

        return newTable; 
}

static unsigned determine_table_size(unsigned num_elems)
{
        unsigned i;
        unsigned table_size; 

        if ((num_elems * 2) > list_of_primes[NELEMS(list_of_primes) - 1]) {
                return num_elems * 2; 
        }

        for (i = 1; i < NELEMS(list_of_primes); i++) {
                if (num_elems * 2 < list_of_primes[i]) {
                        table_size = list_of_primes[i]; 
                        break;
                }
        }

        return table_size;
}

unsigned hashtable_size(T table)
{
        assert(table != NULL); 
        return table->table_size;
}

unsigned hashtable_elems(T table)
{
        assert(table != NULL); 
        return table->elements_stored; 
}

void insert_item(T table, char* key, char* value)
{
        assert(table != NULL); 
        assert(key != NULL); 

        table->elements_stored += 1; 
        is_full_table(table); 

        DataItem new_data; 
        unsigned long index = hash((unsigned char*) key) % table->table_size;

        new_data.key = key; 
        new_data.value = value; 

        index = adjust_index_linear_probe(table, index); 

        table->array[index] = new_data; 

}

static void is_full_table(T table)
{
        if (table->elements_stored == table->table_size) { 
                fprintf(stderr, "Table is full, no room to insert.\n");
                fprintf(stderr, "Exiting.\n"); 
                exit(EXIT_FAILURE); 
        } 
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

static unsigned long adjust_index_linear_probe(T table, unsigned long index)
{
        while(table->array[index].key != NULL) {
                index++; 
                if (index == table->table_size)
                        index = 0; 
        }

        return index; 
}

DataItem get_DataItem_with_key(T table, char* key)
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

void dealloc_hashtable(T table)
{
        free(table->array);
        free(table);
        table = NULL; 
}
