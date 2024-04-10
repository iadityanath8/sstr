#ifndef SSTR_H
#define SSTR_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>   /* Dependency is questioning */

#define unimplemented do{\
  assert(false && "NOT IMPLMENTED YET");\
}while(0);
#define auto __auto_type
#define DEFAULT_CAP_SIZE 16
#define SSTR_SEED_SIZE 2
#define SSTRINLINE __attribute__((always_inline))

/********* MACROS FOR MAKING LIFE EASY **********/
/********* Will be making MACROS name more catchy soon ******/

#define len(x) sstr_len(x)
#define cap(x) sstr_cap(x)
#define SB(x) builder(x)
#define EQ(X,Y) sstr_eq(X,Y)

typedef struct{
  size_t len;
  size_t cap;
}header_t;

typedef char* sstr;

/***
 *
 *  [--------  _________]
 *            
 *             ^ start of char array
 * ****/
sstr builder(const char* charray);

size_t sstr_len(sstr __s) __attribute__((nonnull(1)));
size_t sstr_cap(sstr __s) __attribute__((nonnull(1)));
void sstr_set_len(sstr __s,size_t len_value) __attribute__((nonnull(1)));
void sstr_set_cap(sstr __s,size_t cap_value) __attribute__((nonnull(1)));
void sstr_free(sstr __s) __attribute__((nonnull(1)));
bool sstr_eq(sstr __s, sstr __b) __attribute__((nonnull(1,2)));
/***
 *
 *  
 *  Possibly doubling the capacity in here 
 *  can change the capacity after doubling it 
 *  soon custom allocator option will be given to te user
 *
 * */
sstr sstr_reallocate(sstr a,ssize_t relseed) __attribute__((nonnull(1)));

void sstr_append_char(sstr a[static 1],char val) __attribute__((nonnull(1)));

void sstr_append_cstr(sstr a[static 1],const char* val) __attribute__((nonnull(1)));

void sstr_cat(sstr dest[static 1], sstr src)__attribute__((nonnull(1)));

sstr* split(sstr __s[static 1]) __attribute__((nonnull(1)));

sstr sstr_dup(sstr __s) __attribute__((nonnull(1)));

sstr sstr_move(sstr __s) __attribute__((nonnull(1)));

#endif
