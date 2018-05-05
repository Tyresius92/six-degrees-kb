#include "linkedlist.h"
#include "listunit.h"

void run_linkedlist_tests()
{
        test_new_list(); 
        test_list_length_empty_list();
        test_get_first_node_empty_list(); 
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

void test_get_first_node_empty_list()
{
        fprintf(stderr, "***** Calling test_get_first_node_empty_list *****\n");

        List_t test_list = NULL; 
        ListNode *test_node; 

        test_list = List_new(); 

        if (test_list == NULL) {
                fprintf(stderr, "List_new allocation failed!\n"); 
                exit(EXIT_FAILURE); 
        }

        test_node = get_first_node(test_list); 

        if (test_node != NULL) {
                fprintf(stderr, "head not set to NULL in list_new!\n"); 
                exit(EXIT_FAILURE); 
        }

        free(test_list); 
        test_list = NULL; 

        fprintf(stderr, "Test passes\n"); 

        fprintf(stderr, 
                "***** Leaving test_get_first_node_empty_list *****\n\n");
}