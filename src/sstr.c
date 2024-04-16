#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include "../include/sstr.h"


sstr sstr_new(const char* cstr){
  auto p_len = strlen(cstr); 

  auto header = ALLOC_SSTR(p_len);

  header->cap = p_len + INIT_CAP_SIZE;     // Dangerous
  header->len = p_len;

#if XPRIMENT
  header->st = 0;
  header->ed = p_len;
#endif

  auto __p_str = GET_STRING(header);

  strncpy(__p_str,cstr,p_len + 1);
  return __p_str;
}

sstr sstr_empty(){
  auto header = ALLOC_SSTR(0);

  header->len = 0;
  header->cap = INIT_CAP_SIZE;

#if XPRIMENT
  header->st = 0;
  header->ed = 0;
#endif

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

sstr sstr_reallocate(sstr a){
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

#if XPRIMENT
  new_header->st = 0;
  new_header->ed = len;
#endif

  auto ss = GET_STRING(new_header);
  //printf("%s\n",ss);

  return ss;
}

sstr sstr_ensure_capacity(sstr a,size_t len){
  size_t cap_a = sstr_cap(a);
  auto header = GET_HEADER(a);

  if(cap_a > len + 2){
   puts("MEOW\n");
   return a;
  }else{
    sstr_special_header_t* new_seed = (sstr_special_header_t*)realloc(header,len);
    new_seed->cap = len;
    auto str_val = GET_STRING(new_seed);
    return str_val;
  }
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

sstr sstr_cat(sstr _a,sstr _b){
  sstr b = sstr_empty();
  sstr_append_sstr(&b,_a);
  sstr_append_sstr(&b,_b);

  return b;
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

sstr sstr_dup(sstr __s){
  auto len = sstr_len(__s);
  sstr_special_header_t* header = ALLOC_SSTR(len);  
  header->len = len;
  header->cap = sstr_cap(__s);
  header->st = 0;
  header->ed = len;

  sstr val = GET_STRING(header);

  strncpy(val,__s,len + 1);

  return val;
}

// Tokenization 

void sstr_trim_left(sstr ch){
  size_t i = 0;
  size_t len = sstr_len(ch); 

  while(i < len && isspace(ch[i])){
    i++;
  }

#if XPRIMENT
  memmove(ch,ch + i,len - i);
  ch[len - i] = '\0';
  sstr_special_header_t* header = GET_HEADER(ch);
  header->len = len - i;
#endif
}

void sstr_trim_right(sstr ch){
  size_t len = sstr_len(ch);
  ssize_t i = len - 1;

  while(i >= 0 && isspace(ch[i])){
    i--;
  }

#if XPRIMENT   
  // No need of memmmove
  ch[i + 1] = '\0';
  sstr_special_header_t* header = GET_HEADER(ch);
  header->len = i + 1;
#endif
}

sstr* sstr_split(sstr a,const char __delim,size_t* out_len){
  size_t len = sstr_len(a);
  size_t i = 0;
  size_t p = 0;
  char* bptr = a + p;

  sstr* spage = malloc(sizeof(sstr)*len);
  size_t sidx = 0;

  while(i < len){
    if(a[i] == __delim){

#if DBG(0)
      printlen(bptr,p,i);
#endif
      sstr ap = sstr_empty();

      FOR_APPEND_FROM_TO(&ap,p,i,bptr);
      spage[sidx] = ap;
      sidx++;
      p = i + 1;
    }
    i++;
  }

  assert(*bptr != '\0');

  sstr ap = sstr_empty();
  FOR_APPEND_FROM_TO(&ap,p,i,bptr);

  spage[sidx] = ap;
  sidx++;

#if DBG(0) 
  printlen(bptr,p,i);
#endif
  *out_len = sidx;
  return spage;
}

void sstr_freeList(sstr* fp,size_t len){
  for(int i = 0;i < len;i++) 
    sstr_free(fp[i]);

  free(fp);
}

#if 1
int main(){
  auto a = sstr_empty();
  printf("%ld\n",sstr_cap(a));
  a = sstr_ensure_capacity(a,23);

  printf("%ld\n",sstr_cap(a));
  return 0;
}

#endif

