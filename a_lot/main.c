#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


#include "test.h"




void load_all_plugins(int argc , char *argv[])
{
    int i;
    void* handle = NULL;

    for(i=1 ; i<argc ; i++)
    {
        printf("#### try to load %s\n" , argv[i]);
        handle = dlopen( argv[i] , RTLD_LAZY );

        if( !handle )
        {
            printf("#### load %s fail : %s\n" ,  argv[i] , dlerror());
        }
    }
}


void call_all_reg_func()
{
    test_reg_t *reg_ptr;
    reg_ptr = reg_main.next;

    while(reg_ptr != NULL)
    {
        reg_ptr->func();
        reg_ptr = reg_ptr->next;
    }
}


int main(int argc , char *argv[])
{
    int i;
    void* handle = NULL;

    printf("---- Enter main ----\n");


    /***** load plugin ****/

    load_all_plugins(argc , argv);

    /***** call function in plugin****/
    
    call_all_reg_func();
    

    /***** exit ****/

    printf("---- Leave main ----\n");


}

