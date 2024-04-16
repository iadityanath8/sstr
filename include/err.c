#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <assert.h>


jmp_buf jexcet;

int db0(int a,int b){
  int c= a/b;
  
  return c;
}

int main(){
  int a = db0(1,2);
  return 0;
}
