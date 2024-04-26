#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/sstr.h"

void shakes_pear(){
  sstr a = sstr_new("Crabbed Age and Youth"
      "Cannot live together:"
      "Youth is full of pleasance,"
      "Age is full of care;"
      "Youth like summer morn,"
      "Age like winter weather;"
      "Age, I do defy thee-"
      "O sweet shepherd, hie thee,"
      "For methinks thou stay'st too long.");
  
  int page_len = {0};
  sstr* po = sstr_split(a,' ',&page_len);
  
  for(int i =0;i < page_len;i++){
    printf("%s\n",po[i]);
  }
  
  sstr_freeList(po,page_len);
  
  printf("UP => %p\n",a);
  sstr_free(a);
}

int main(){
  sstr b = sstr_new("MEOW BILLA");//malloc(sizeof(char)*5);
  printf("DOWN => %s\n",b);
  sstr_free(b);
  return 0;
}
