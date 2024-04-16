#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define GET_HEADER(x) (sstr_special_header_t*)((char*)x - sizeof(sstr_special_header_t))
#define GET_STRING(x) (sstr)((char*)x + sizeof(sstr_special_header_t))
#define ALLOC_SSTR(len) (sstr_special_header_t*)s_alloc(sizeof(sstr_special_header_t) + \
                                        sizeof(char)*(len + 1 + INIT_CAP_SIZE));

#define FOR_APPEND_FROM_TO(TO,beg,end,ptr) do{\
  for(int res__ = beg;res__ < end;res__++){\
    sstr_append_char(TO,ptr[res__]);\
  }\
  }while(0);


#define printlen(a,st,end){\
  for(size_t idx = st;idx < end;idx++){\
    printf("%c",a[idx]);\
  }printf("\n");\
  \
}


#define S_EQ(x,y) sstr_eq(x,y)
#define SB(x) sstr_new(x)
#define len(x) sstr_len(x)
#define cap(x) sstr_cap(x)

#define XPRIMENT 1
#define DBG(X) X

#define unimplemented do{\
  assert(false && "NOT IMPLEMENRTED");\
}while(0);

#define INIT_CAP_SIZE 2           /* ONLY FOR TESTING PURPOSE **/
#define INIT_GROW_SIZE 2

#ifndef s_alloc
#define s_alloc malloc
#endif


#define auto __auto_type


typedef char* sstr;

typedef struct{
#if XPRIMENT
  size_t st;
  size_t ed;
#endif
  size_t len;
  size_t cap;
}sstr_special_header_t;

enum{
  IN_FREE,
  NO_FREE,
};

sstr sstr_new(const char* cstr);

sstr sstr_empty();

size_t sstr_len(sstr __a);

size_t sstr_cap(sstr __a);

void sstr_set_len(sstr __s,size_t len);

void sstr_set_cap(sstr __s,size_t cap);
void sstr_free(sstr _a);

sstr sstr_reallocate(sstr a);
sstr sstr_ensure_capacity(sstr a,size_t len);

void sstr_append_char(sstr __s[static 1],char _app);

void sstr_append_str(sstr a[static 1], const char* __a);

void sstr_append_sstr(sstr a[static 1],sstr appender);

sstr sstr_cat(sstr a,sstr b);

bool sstr_find(sstr a,const char delim);

bool sstr_eq(sstr a,sstr b);

char sstr_at(sstr __a, ssize_t sidx);
char* view_chr();

sstr* sstr_split(sstr __a,const char __delim,size_t* page_len);

void sstr_freeList(sstr* p,size_t len);


