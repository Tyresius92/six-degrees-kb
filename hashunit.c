#include "hashunit.h"
#include "hashtable.h"

void test_alloc_hashtable()
{
        fprintf(stderr, "********** Calling test_alloc_hashtable **********\n");
        Hashtable_t testTable = NULL; 

        unsigned elems = 10;

        testTable = alloc_hashtable(elems);

        assert(testTable != NULL); 
        fprintf(stderr, "Alloc Successful!\n");

        free(testTable); 
        free(testTable->array); 
        fprintf(stderr, 
                "********** Leaving test_alloc_hashtable **********\n\n");
}

void test_alloc_big_hashtable()
{
        fprintf(stderr, 
                "********** Calling test_alloc_big_hashtable **********\n");
        Hashtable_t testTable = NULL; 

        unsigned elems = 10000000;

        testTable = alloc_hashtable(elems);

        assert(testTable != NULL); 
        fprintf(stderr, "Alloc Successful!\n");

        free(testTable->array); 
        fprintf(stderr, 
                "********** Leaving test_alloc_big_hashtable **********\n\n");
}

void test_dealloc_hashtable()
{
        fprintf(stderr, 
                "********** Calling test_dealloc_hashtable **********\n");
        Hashtable_t testTable = NULL;

        testTable = alloc_hashtable(5); 

        assert(testTable != NULL); 
        fprintf(stderr, "Alloc Successful!\n"); 
        fprintf(stderr, "Deallocating\n"); 

        dealloc_hashtable(testTable); 
        testTable = NULL;
        assert(testTable == NULL); 

        fprintf(stderr, "Deallocation Successful!\n");
        fprintf(stderr, 
                "********** Leaving test_dealloc_hashtable **********\n\n");
}

void test_insert_item()
{
        fprintf(stderr, "********** Calling test_insert_item **********\n");
        Hashtable_t testTable = NULL; 

        testTable = alloc_hashtable(5); 

        assert(testTable != NULL); 
        fprintf(stderr, "Alloc Successful!\n");
        fprintf(stderr, "Calling insert\n");

        insert_item(testTable, "testing", "hello\n"); 

        fprintf(stderr, "Deallocating\n"); 

        dealloc_hashtable(testTable); 
        testTable = NULL;
        assert(testTable == NULL); 

        fprintf(stderr, "Deallocation Successful!\n");
        fprintf(stderr, "********** Leaving test_insert_item **********\n\n");
}

void test_insert_many_items()
{
        fprintf(stderr, 
                "********** Calling test_insert_many_items **********\n");
        Hashtable_t testTable = NULL; 

        testTable = alloc_hashtable(5); 
        char *testKey[] = { "test1", "test2", "test3", "4test", "test5" };
        char *testValue[] = { "hello\n", "goodbye\n", "what up\n", 
                            "banana\n", "i\n" };

        assert(testTable != NULL); 
        fprintf(stderr, "Calling insert repeatedly\n");

        for (int i = 0; i < 5; i++) {
                insert_item(testTable, testKey[i], testValue[i]);
        }

        for (int i = 0; i < 5; i++) {
                DataItem test_data = get_DataItem_with_key(testTable, 
                                                           testKey[i]); 

                fprintf(stderr, "%s: %s", test_data.key, test_data.value); 

                if (test_data.value == testValue[i])
                        fprintf(stderr, "Test Passes\n"); 
                else 
                        fprintf(stderr, "Test Fails\n");
        }         

        fprintf(stderr, "Deallocating\n"); 

        dealloc_hashtable(testTable); 
        testTable = NULL;
        assert(testTable == NULL); 

        fprintf(stderr, 
                "********** Leaving test_insert_many_items **********\n\n");
}

void test_get_DataItem_with_key()
{
        fprintf(stderr, 
                "********** Calling test_get_DataItem_with_key **********\n");
        
        Hashtable_t testTable = NULL; 
        char *testKey = "testing";
        char *testValue = "hello\n"; 

        testTable = alloc_hashtable(5); 

        assert(testTable != NULL); 
        fprintf(stderr, "Alloc Successful!\n");
        fprintf(stderr, "Calling insert\n");

        insert_item(testTable, testKey, testValue); 

        DataItem test_data = get_DataItem_with_key(testTable, testKey); 

        fprintf(stderr, "returned testValue: %s", test_data.value); 

        if (test_data.value == testValue)
                fprintf(stderr, "Test Passes\n"); 
        else 
                fprintf(stderr, "Test Fails\n");

        fprintf(stderr, "Deallocating\n"); 

        dealloc_hashtable(testTable); 
        testTable = NULL;
        assert(testTable == NULL); 

        fprintf(stderr, "Deallocation Successful!\n");
        fprintf(stderr, "********** Leaving test_insert_item **********\n\n");
}