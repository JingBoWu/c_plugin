#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


#include "test.h"


static void __attribute__ ((constructor))						
constructor_test_func (void)			
{									
    printf("Call constructor_test_func\n");
}									


int main(int argc , char *argv[])
{
    int i;
    void* handle = NULL;

    printf("Enter main\n");


    /***** load plugin ****/
    if(argc == 2)
    {
        handle = dlopen( argv[1] , RTLD_LAZY );

        if( !handle )
        {
            fprintf( stderr, "[%s](%d) dlopen get error: %s\n", __FILE__, __LINE__, dlerror() );
            exit( EXIT_FAILURE );
        }
    }

    /***** call function in plugin****/
    if(reg_func)
    {
        reg_func();
    }

    printf("do someting in main....\n");


    /***** exit ****/

    if(handle)
    {
        dlclose( handle );
    }

    printf("Leave main\n");


}

