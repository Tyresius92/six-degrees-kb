#include "linkedlist.h"
#include "listunit.h"

void run_linkedlist_tests()
{
        test_new_list(); 
        test_list_length_empty_list();
        test_get_string_empty_list(); 
        test_insert_front(); 
        test_insert_several_items(); 
        test_list_clear(); 
        test_destroy_list(); 
}

void test_new_list()
{
        fprintf(stderr, "***** Calling test_new_list *****\n");

        List_t test_list = NULL;  

        test_list = List_new(); 

        if (test_list == NULL) {
                fprintf(stderr, "List_new allocation failed!\n"); 
                exit(EXIT_FAILURE); 
        }

        free(test_list); 
        test_list = NULL; 

        fprintf(stderr, "Test passes\n");

        fprintf(stderr, "***** Leaving test_new_list *****\n\n");
}

void test_list_length_empty_list()
{
        fprintf(stderr, "***** Calling test_list_length_empty_list *****\n");

        List_t test_list = NULL; 
        int test_length = -1; 

        test_list = List_new(); 

        if (test_list == NULL) {
                fprintf(stderr, "List_new allocation failed!\n"); 
                exit(EXIT_FAILURE); 
        }

        test_length = List_length(test_list); 

        if (test_length != 0) {
                fprintf(stderr, "length not set in list_new!\n"); 
                exit(EXIT_FAILURE); 
        }

        free(test_list); 
        test_list = NULL; 

        fprintf(stderr, "Test passes\n"); 

        fprintf(stderr, "***** Leaving test_list_length_empty_list *****\n\n");
}

void test_get_string_empty_list()
{
        fprintf(stderr, "***** Calling test_get_string_empty_list *****\n");

        List_t test_list = NULL; 
        char *test_string; 

        test_list = List_new(); 

        if (test_list == NULL) {
                fprintf(stderr, "List_new allocation failed!\n"); 
                exit(EXIT_FAILURE); 
        }

        test_string = get_string(test_list, 0); 

        if (test_string != NULL) {
                fprintf(stderr, "head not set to NULL in list_new!\n"); 
                exit(EXIT_FAILURE); 
        }

        free(test_list); 
        test_list = NULL; 

        fprintf(stderr, "Test passes\n"); 

        fprintf(stderr, 
                "***** Leaving test_get_string_empty_list *****\n\n");
}

void test_insert_front()
{
        fprintf(stderr, "***** Calling test_insert_front *****\n"); 

        List_t test_list = NULL; 
        char *test_string = "hello"; 
        char *verify_string = NULL; 

        test_list = List_new(); 

        insert_front(test_list, test_string); 

        verify_string = get_string(test_list, 0); 

        if (test_string != verify_string) {
                fprintf(stderr, "Insertion or retrieval failed!\n");
                fprintf(stderr, "Verify string != test string\n"); 
                exit(EXIT_FAILURE); 
        }

        List_destroy(test_list); 
        test_list = NULL; 

        fprintf(stderr, "Test passes\n");

        fprintf(stderr, "***** Leaving test_insert_front *****\n\n");
}

void test_insert_several_items()
{
        fprintf(stderr, "***** Calling test_insert_several_items *****\n"); 

        List_t test_list = NULL; 
        char *test_strings[] = { "you say", "goodbye", "i say", "hello" };
        char *verify_string = NULL; 

        test_list = List_new(); 

        for (int i = 0; i < 4; i++) {
                insert_front(test_list, test_strings[i]);
        }

        for (int i = 0; i < 4; i++) {
                verify_string = get_string(test_list, i); 

                if (test_strings[3 - i] != verify_string) {
                        fprintf(stderr, "Insertion or retrieval failed!\n");
                        fprintf(stderr, "Verify string != test string\n"); 
                        exit(EXIT_FAILURE); 
                }
        }

        List_destroy(test_list); 
        test_list = NULL; 

        fprintf(stderr, "Test passes\n"); 

        fprintf(stderr, "***** Leaving test_insert_several_items *****\n\n");
}

void test_list_clear()
{
        fprintf(stderr, "***** Calling test_list_clear *****\n"); 

        List_t test_list = NULL; 
        char *test_strings[] = { "you say", "goodbye", "i say", "hello" };
        char *verify_string = NULL; 

        test_list = List_new(); 

        for (int i = 0; i < 4; i++) {
                insert_front(test_list, test_strings[i]);
        }

        List_clear(test_list); 

        verify_string = get_string(test_list, 0); 

        if (verify_string != NULL) {
                fprintf(stderr, "List_clear failed!\n");
                exit(EXIT_FAILURE); 
        }

        List_destroy(test_list); 
        test_list = NULL; 

        fprintf(stderr, "Test passes\n"); 

        fprintf(stderr, "***** Leaving test_list_clear *****\n\n");
}

//this test should be run with valgrind
void test_destroy_list()
{
        fprintf(stderr, "***** Calling test_destroy_list *****\n"); 

        List_t test_list = NULL; 
        char *test_strings[] = { "you say", "goodbye", "i say", "hello" };
        char *verify_string = NULL; 

        test_list = List_new(); 

        for (int i = 0; i < 4; i++) {
                insert_front(test_list, test_strings[i]);
        }

        List_clear(test_list); 

        verify_string = get_string(test_list, 0); 

        if (verify_string != NULL) {
                fprintf(stderr, "List_clear failed!\n");
                exit(EXIT_FAILURE); 
        }

        List_destroy(test_list); 
        test_list = NULL; 

        fprintf(stderr, "Test passes\n"); 

        fprintf(stderr, "***** Leaving test_destroy_list *****\n\n");
}

