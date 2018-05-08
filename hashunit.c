#include "hashunit.h"
#include "hashtable.h"

void run_hashtable_tests()
{
        test_alloc_hashtable();
        test_alloc_big_hashtable();
        test_dealloc_hashtable();
        test_insert_item(); 
        test_insert_and_retrieve_five_items();
        test_get_DataItem_with_key();
}

/* 
 * This test will still result in memory leaks. 
 * Hidden array is allocated, but not deallocated.
 */
void test_alloc_hashtable()
{
        fprintf(stderr, "***** Calling test_alloc_hashtable *****\n");
        Hashtable_t testTable = NULL; 

        unsigned elems = 10;

        testTable = alloc_hashtable(elems);

        assert(testTable != NULL); 
        fprintf(stderr, "Test Passes\n");

        dealloc_hashtable(testTable); 
        fprintf(stderr, "***** Leaving test_alloc_hashtable *****\n\n");
}

/* 
 * This test will still result in memory leaks. 
 * Hidden array is allocated, but not deallocated.
 */
void test_alloc_big_hashtable()
{
        fprintf(stderr, "***** Calling test_alloc_big_hashtable *****\n");
        Hashtable_t testTable = NULL; 

        unsigned elems = 10000000;

        testTable = alloc_hashtable(elems);

        assert(testTable != NULL); 
        fprintf(stderr, "Test Passes\n");

        dealloc_hashtable(testTable);  
        fprintf(stderr, "***** Leaving test_alloc_big_hashtable *****\n\n");
}

void test_dealloc_hashtable()
{
        fprintf(stderr, "***** Calling test_dealloc_hashtable *****\n");
        Hashtable_t testTable = NULL;

        testTable = alloc_hashtable(5); 

        assert(testTable != NULL); 

        dealloc_hashtable(testTable); 
        testTable = NULL;
        assert(testTable == NULL); 

        fprintf(stderr, "Test Passes\n");
        fprintf(stderr, "***** Leaving test_dealloc_hashtable *****\n\n");
}

void test_insert_item()
{
        fprintf(stderr, "***** Calling test_insert_item *****\n");
        Hashtable_t testTable = NULL; 

        testTable = alloc_hashtable(5); 

        assert(testTable != NULL); 

        insert_item(testTable, "testing", "hello\n"); 

        fprintf(stderr, "Test Passes\n"); 

        dealloc_hashtable(testTable); 
        testTable = NULL;
        assert(testTable == NULL); 

        fprintf(stderr, "***** Leaving test_insert_item *****\n\n");
}

void test_insert_and_retrieve_five_items()
{
        fprintf(stderr, 
                "***** Calling test_insert_and_retrieve_many_items *****\n");
        Hashtable_t testTable = NULL; 

        testTable = alloc_hashtable(5); 
        char *testKey[] = { "test1", "test2", "test3", "4test", "test5" };
        char *testValue[] = { "hello\n", "goodbye\n", "what up\n", 
                            "banana\n", "i'm hungry\n" };

        assert(testTable != NULL); 

        for (int i = 0; i < 5; i++) {
                insert_item(testTable, testKey[i], (void *) testValue[i]);
        }

        for (int i = 0; i < 5; i++) {
                DataItem test_data = get_DataItem_with_key(testTable, 
                                                           testKey[i]); 

                if (test_data.value != testValue[i]) {
                        fprintf(stderr, "Test Fails\n"); 
                        fprintf(stderr, "Expected key-value pair: [%s]:[%s]\n", 
                                testKey[i], testValue[i]);
                        fprintf(stderr, "Key-value pair returned: [%s]:[%s]\n", 
                                testKey[i], (char *) test_data.value); 
                        exit(EXIT_FAILURE); 
                }
        }         

        fprintf(stderr, "Test Passes\n"); 

        dealloc_hashtable(testTable); 
        testTable = NULL;
        assert(testTable == NULL); 

        fprintf(stderr, 
                "***** Leaving test_insert_and_retrieve_many_items *****\n\n");
}

void test_get_DataItem_with_key()
{
        fprintf(stderr, 
                "***** Calling test_get_DataItem_with_key *****\n");
        
        Hashtable_t testTable = NULL; 
        char *testKey = "testing";
        char *testValue = "hello\n"; 

        testTable = alloc_hashtable(5); 

        assert(testTable != NULL); 

        insert_item(testTable, testKey, (void *) testValue); 

        DataItem test_data = get_DataItem_with_key(testTable, testKey); 

        if (test_data.value != testValue) {
                fprintf(stderr, "Test Fails\n"); 
                fprintf(stderr, "Expected key-value pair: [%s]:[%s]\n", 
                        testKey, testValue);
                fprintf(stderr, "Returned key-value pair: [%s]:[%s]\n", 
                        testKey, (char *) test_data.value); 
                exit(EXIT_FAILURE); 
        }

        fprintf(stderr, "Test Passes\n");

        dealloc_hashtable(testTable); 
        testTable = NULL;
        assert(testTable == NULL); 

        fprintf(stderr, "***** Leaving test_get_DataItem_with_key *****\n\n");
}
