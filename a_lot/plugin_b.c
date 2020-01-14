#include <stdio.h>


#include "test.h"


static void func_plugin()
{
    printf("this is a function in plugin b\n");
}


test_reg_t reg_b ={
    .func = func_plugin,
};

static void __attribute__ ((constructor))						
registe_func_b (void)			
{									
    // printf("Enter registe_func_b....\n");

    
    reg_b.next = reg_main.next;
    reg_main.next = &reg_b;


    // printf("Leave registe_func_b....\n");
}									