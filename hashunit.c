#include "hashunit.h"
#include "hashtable.h"

int main()
{
        Hashtable_t testTable = NULL; 

        testTable = alloc_hashtable(5);

        assert(testTable != NULL); 
        printf("Alloc Successful!");

        return 0; 
}