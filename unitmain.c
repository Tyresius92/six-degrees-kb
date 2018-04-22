#include "hashunit.h"
#include "hashtable.h"

int main()
{
        //test_alloc_hashtable();
        //test_alloc_big_hashtable();
        test_dealloc_hashtable();
        test_insert_item(); 
        test_insert_many_items();
        test_get_DataItem_with_key();

        return 0; 
}