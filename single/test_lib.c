#include <stdio.h>

#include "test.h"


static void __attribute__ ((constructor))						
constructor_test_func (void)			
{									
    printf("Call constructor_test_func in test_lib\n");
}									


test_func_t reg_func = 0;
