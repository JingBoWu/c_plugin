#include <stdio.h>


#include "test.h"


static void func_plugin()
{
    printf("this is a function in plugin a\n");
}


test_reg_t reg_a ={
    .func = func_plugin,
};

static void __attribute__ ((constructor))						
registe_func_a (void)			
{									
    // printf("Enter registe_func_a....\n");

    
    reg_a.next = reg_main.next;
    reg_main.next = &reg_a;


    // printf("Leave registe_func_a....\n");
}									