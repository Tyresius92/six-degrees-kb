#include "hashunit.h"
#include "hashtable.h"

void test_alloc_hashtable()
{
        Hashtable_t testTable = NULL; 

        testTable = alloc_hashtable(5);

        assert(testTable != NULL); 
        printf("Alloc Successful!\n");
}

void test_dealloc_hashtable()
{
        Hashtable_t testTable = NULL;

        testTable = alloc_hashtable(5); 

        assert(testTable != NULL); 
        printf("Alloc Successful!\n"); 
        printf("Deallocating\n"); 

        dealloc_hashtable(testTable); 
        testTable = NULL;
        assert(testTable == NULL); 
}