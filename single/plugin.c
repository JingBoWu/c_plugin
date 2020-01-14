#include <stdio.h>


#include "test.h"


static void func_plugin()
{
    printf("this is a function in plugin\n");
}


static void __attribute__ ((constructor))						
registe_func_a (void)			
{									
    printf("Enter registe_func_a....\n");

    
    reg_func = func_plugin;


    printf("Leave registe_func_a....\n");
}									