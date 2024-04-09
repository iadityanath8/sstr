#include <stdio.h>
#include "../include/sstr.h"

#if 0
int main(){
    sstr a = builder("nemesis");
    sstr b = builder("main");

    sstr_cat(&a, &b);
    //printf("%d %d\n",b.len, b.cap); 
    //sstr_push(&b, 'i');

    //printf("%d %d\n",b.len, b.cap);
    sstr_print_debug(&a, SSTR_NEWLINE);
    sstr_free(&a);
    sstr_free(&b);
    return 0;
}
#endif

int main(){
  sstr a = builder("MALLU");
  char* b = builder("AMAN AND");

  sstr_append_cstr(&a,"MADHAR");
  
  sstr_cat(&b,a);

  printf("%s\n",b);
  printf("%ld\n",sstr_len(a));
  sstr_free(a);
  sstr_free(b);
  return 0;
}
