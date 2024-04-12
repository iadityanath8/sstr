#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/sstr.h"


sstr sstr_new(const char* cstr){
  auto p_len = strlen(cstr); 

  auto header = ALLOC_SSTR(p_len);
  
  header->cap = p_len + INIT_CAP_SIZE;     // Dangerous
  header->len = p_len;
  header->st = 0;
  header->ed = p_len;

  auto __p_str = GET_STRING(header);
  
  strncpy(__p_str,cstr,p_len + 1);
  return __p_str;
}

sstr sstr_empty(){
  auto header = ALLOC_SSTR(0);
  
  header->len = 0;
  header->cap = INIT_CAP_SIZE;
  header->st = 0;
  header->ed = 0;
  auto __str_val = GET_STRING(header);
  
  strncpy(__str_val,"",0 + 1);

  return GET_STRING(header);
}

size_t sstr_len(sstr __a){
  auto header = GET_HEADER(__a);
  
#if XPRIMENT
  if(header->ed - header->st == header->len){
    return header->ed - header->st;
  } else{
    return header->ed - header->st;
  }
#endif
  return header->len;
}

size_t sstr_cap(sstr __a){
  auto header = GET_HEADER(__a);
  return header->cap;
}

void sstr_set_len(sstr __s,size_t len){
  auto header = GET_HEADER(__s);
#if XPRIMENT
  if(header->ed - header->st == header->len){
    header->ed = len;
  }else{
    unimplemented
  }
  header->len = header->ed - header->st;
#endif
  header->len = len;
}

void sstr_set_cap(sstr __s,size_t cap){
  auto header = GET_HEADER(__s);
  header->cap = cap;
}

void sstr_free(sstr _a){
  assert(_a != NULL);
  
  auto header = GET_HEADER(_a);
   
  free(header);
  header = NULL;
}

static inline sstr sstr_reallocate(sstr a){
  auto len = sstr_len(a);
  auto cap = sstr_cap(a);
  
  auto header = GET_HEADER(a);
#if Dangerous
  if(len + 2 == cap){

  }
#endif
 
  auto new_header = (sstr_special_header_t*)
                  realloc(header,sizeof(sstr_special_header_t) +
                      sizeof(char)*(cap*INIT_GROW_SIZE + 1));
  
  new_header->cap = cap*INIT_GROW_SIZE;
  new_header->len = len;
  new_header->st = 0;
  new_header->ed = len;
  
  auto ss = GET_STRING(new_header);
  //printf("%s\n",ss);
  
  return ss;
}

void sstr_append_char(sstr __s[static 1],char _app){
  auto len = sstr_len(__s[0]);
  auto cap = sstr_cap(__s[0]);
  
  if(len + 2 == cap){
    __s[0] = sstr_reallocate(__s[0]);
    __s[0][len] = _app;
  }else{
    __s[0][len] = _app;
  }
  
  __s[0][len + 1] = '\0';
  sstr_set_len(__s[0],len + 1);
}

void sstr_append_str(sstr a[static 1], const char* __a){
  for(size_t i = 0;i < strlen(__a);i++){
    sstr_append_char(a,__a[i]);
  }
}

void sstr_append_sstr(sstr a[static 1],sstr appender){
  for(size_t i = 0;i < sstr_len(appender);i++){
    sstr_append_char(a,appender[i]);
  }
}

bool sstr_find(sstr a,const char delim){
  for(size_t i = 0;i < sstr_len(a);i++){
    if(delim == a[i]){
      return i;
    }
  }
  return -1;
}

bool sstr_eq(sstr a,sstr b){
  auto a_len = sstr_len(a);
  auto b_len = sstr_len(b);

  if(a_len != b_len){return false;}
  return !strncmp(a,b,a_len);
}

char sstr_at(sstr __a, ssize_t sidx){
  auto __a_len = sstr_len(__a);
  
   if(sidx >= (ssize_t)__a_len || 
      sidx + __a_len >= __a_len){fprintf(stderr,"INDEX OUT OF BOUND"); exit(EXIT_FAILURE);}

#if XPRIMENT
  if(sidx < 0){
    // sidx = -1
    // len + sidx;
    return __a[sidx + __a_len];
  }
  return __a[sidx];
#endif
  return __a[sidx];
}

char* view_chr(){
  unimplemented
}

sstr* sstr_split(sstr __a,const char __delim){
  unimplemented
}

int main(){
  auto a = sstr_new("MEOW");
  auto b = sstr_new("MEOW");   
  

  sstr_free(a);
  sstr_free(b);
  return 0;
}


