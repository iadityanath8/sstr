#include <stdio.h>

#define TEST_IMPL

#include "sstr.h"

int main(){
    sstr a = builder("nemesis");
    sstr b = builder("main");

    sstr_cat(&a, &b);
    //printf("%d %d\n",b.len, b.cap); 
    //sstr_push(&b, 'i');

    //printf("%d %d\n",b.len, b.cap);
    sstr_print_debug(&a, SSTR_NEWLINE);
    return 0;
}
