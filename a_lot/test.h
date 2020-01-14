#ifndef __include_test_h__
#define __include_test_h__

typedef void (*test_func_t)();


typedef struct test_reg{
    struct test_reg *next;
    test_func_t func;
}test_reg_t;


extern test_reg_t reg_main;


#endif