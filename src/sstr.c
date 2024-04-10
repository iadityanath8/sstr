#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>   /* Dependency is questioning */
#include "../include/sstr.h"
/***
 *
 *  [-------- _________]
 *            
 *   ^        ^ start of char array
 * ****/
sstr builder(const char* charray){
  size_t len = strlen(charray);
  auto header = (header_t*)malloc(sizeof(header_t) + sizeof(char)*(len + DEFAULT_CAP_SIZE + 1));
  header->len = len;
  header->cap = len + DEFAULT_CAP_SIZE;
  
  auto __str = ((char*)header) + sizeof(header_t);

  strncpy(__str,charray,len);
  
  return (sstr)__str;
}

size_t sstr_len(sstr __s){
  auto header = (header_t*)((char*)__s - sizeof(header_t));
  return header->len;
}

size_t sstr_cap(sstr __s){
  auto header = (header_t*)((char*)__s - sizeof(header_t));
  return header->cap;
}

void sstr_set_len(sstr __s,size_t len_value){
  auto header = (header_t*)((char*)__s - sizeof(header_t));
  header->len = len_value;
}

void sstr_set_cap(sstr __s,size_t cap_value){
  auto header = (header_t*)((char*)__s - sizeof(header_t));
  header->cap = cap_value;
}

void sstr_free(sstr __s){
  auto header = (header_t*)((char*)__s - sizeof(header_t));
  free(header);
}

bool sstr_eq(sstr __s,sstr __b){
  assert(__s != NULL && __b != NULL);
  auto len_s = sstr_len(__s);

  if(sstr_len(__s) != sstr_len(__b)) return false;
  
  size_t i = 0;
  
  while(i < sstr_len(__s)){
    if(__s[i] != __b[i]){
      return false;
    }
    i++;
  }
  return true;
}

/***
 *
 *  
 *  Possibly doubling the capacity in here 
 *
 *
 * */

sstr sstr_reallocate(sstr a,ssize_t relseed){
  size_t len = sstr_len(a);
  size_t cap = sstr_cap(a);
  
  if(relseed == -1){
    relseed = cap;
  }
  auto new_header = (header_t*)malloc(sizeof(header_t) + sizeof(char)*relseed*SSTR_SEED_SIZE);
  new_header->len = len;
  new_header->cap = relseed*SSTR_SEED_SIZE;
  auto new_string = (char*)new_header + sizeof(header_t);
  strncpy(new_string,a,len); 
  
  sstr_free(a);
  return new_string;
}


void sstr_append_char(sstr a[static 1],char val){
  auto len = sstr_len(*a);
  auto cap = sstr_cap(*a);

  if(len >= cap){
    *a = sstr_reallocate(*a,-1);  
    a[0][len] = val;
    sstr_set_len(*a,len + 1);
  }else{
    a[0][len] = val;
    sstr_set_len(*a,len + 1);
  }
}

void sstr_append_cstr(sstr a[static 1],const char* val){
  auto c_len = strlen(val);
  for(int i = 0;i < c_len;i++){
    sstr_append_char(a,val[i]);
  }
}

void sstr_cat(sstr dest[static 1], sstr src){
  auto len_dest = sstr_len(dest[0]);
  auto len_src = sstr_len(src);
  auto cap_dest = sstr_cap(dest[0]);

  if(len_dest + len_src < cap_dest){
    int i = 0;
    while(i < len_src){
      sstr_append_char(dest,src[i]);i++;
    }
  }else{
    dest[0] = sstr_reallocate(dest[0],len_dest + len_src);
    int i = 0;
    while(i < len_src){
      sstr_append_char(dest,src[i]);i++;
    }
  }
}

sstr sstr_dup(sstr __s){
  sstr a = builder("");  

  auto __l = sstr_len(__s);
  strncpy(a,__s,__l);
  
  sstr_set_len(a,__l);
  return a;
}

sstr* sstr_split(sstr s,const char delim__){
  /////// returns an alloced array of sstr string value 
  
  /***
   *
   *        SOON WE WILL HAVE THE TRACING GC RELATED TO SSTR STRING ONLY 
   *        SO THAT WE CAN REMOVE THE UNNECCESARY FREE CALLS 
   *
   */
  
  unimplemented
}

sstr sstr_move(sstr __s){
  ////   
  unimplemented;
}

#if 1
int main() {
  sstr a =SB("MEOW");
  sstr b = SB("MEOP");

  return 0;
}

#endif


