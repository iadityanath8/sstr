
#ifndef TEST_H
#define TEST_H
#include <stdio.h>
#include <stdbool.h>
#define SSTR_NEWLINE 0x37
#define SSTR_MASK int
#define SSTR_NO_NEWLINE 0x4BB0

typedef struct{
    char* data;
    int len;
    int cap;
}sstr;

int add(int, sstr);
sstr builder(char* raw);
void sstr_print_debug(sstr*, SSTR_MASK);
void sstr_free(sstr*);
bool sstr_eq(sstr*, sstr*);
void sstr_cat(sstr* dest, sstr* src); //// for testing purpose

#endif // TEST_H

#ifdef TEST_IMPL
#include <stdlib.h>
#include <stdbool.h>
size_t utils_sstr_len(char* a){
    int i = 0;
    size_t len = 0;

    while(a[i] != '\0'){
	len++;
	i++;
    }
    return len;
}

void utils_sstr_copy(char* dest, char* src, size_t len){

    for(int i = 0; i < len;i++){
	dest[i] = src[i];
    }
    
}

void sstr_push(sstr* string_val, char val){
    if(string_val->len >= string_val->cap){
	size_t newcap = string_val->len*2;
	size_t len = string_val->len;
	
	string_val->data = realloc(string_val->data, newcap);
	string_val->data[len] = val;
	string_val->len++;

	string_val->cap = newcap;
    }else{
	string_val->data[string_val->len] = val;
	string_val->len++;
    }
}

sstr builder(char* raw){
    
    size_t normal_len = utils_sstr_len(raw);
    char* data = malloc(sizeof(char)*normal_len);
    sstr a = { 0 };
    utils_sstr_copy(data, raw,normal_len);
    a.len = normal_len;
    a.cap = normal_len;
    a.data = data;
    return a;
}

void sstr_print_debug(sstr* pointer_to_package, SSTR_MASK mask){
    size_t len = pointer_to_package->len;
    
    for(size_t i = 0; i < len;i++){
	printf("%c", pointer_to_package->data[i]);
    }

    if(mask == SSTR_NEWLINE){
	printf("\n");
    }
}

void sstr_free(sstr* string_val){
    free(string_val->data);
    string_val->len = 0;
    string_val->cap = 0;
}

bool runnable_stream(char* raw1, char* raw2, size_t len){
    for(int i = 0; i < len;i++){
	if(raw1[i] != raw2[i]){
	    return false;
	}
    }

    return true;
}

bool sstr_eq(sstr* string_val1, sstr* string_val2){
    if(string_val1->len != string_val2->len){
	return false;
    }
    return runnable_stream(string_val1->data, string_val2->data, string_val1->len);
}

void sstr_cat(sstr* dest, sstr* src){
    size_t i = 0;
    
    while(i < src->len){
	sstr_push(dest, src->data[i]);
	i++;
    }
}

#endif // TEST_IM
