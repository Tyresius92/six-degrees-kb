#include "hashunit.h"
#include "listunit.h"

int main()
{
        run_hashtable_tests();
        run_linkedlist_tests(); 

        fprintf(stderr, "All tests pass.\n"); 

        return 0; 
}