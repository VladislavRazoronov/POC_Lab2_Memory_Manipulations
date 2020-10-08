#include <stdio.h>
#include <string.h>
#include "My_strings.h"

int my_string_t_create(my_string_t* str, size_t buf_size){
    /*
    * A function to create my_string with given buffer size
    * @param my_string_t* str My string that needs to be created
    * @param size_t buf_size The size of it's buffer
    */
    if(!str){
        return NOT_FOUND_CODE;
    }
    str->data = malloc(buf_size + 1);
    if( !str->data ){
        return MEMORY_ALLOCATION_ERR;
    }
    str->size_m = 0;
    str->capacity_m = buf_size;
    return 0;
}



size_t my_str_size(const my_string_t* str){
    if(!str){
        return 0;
    }
    return str->size_m;
}

size_t my_str_capacity(const my_string_t* str){
    if(!str){
        return 0;
    }
    return str->capacity_m;
}

int my_str_empty(const my_string_t* str){
    if(!str){
        return 1;
    }
    return str->size_m==0;
}

int my_str_getc(const my_string_t* str, size_t index){
    if(index > str->size_m){
        return RANGE_ERR;
    }
    if(!str){
        return NOT_FOUND_CODE;
    }
    return str->data[index];
}

const char* my_str_get_cstr(my_string_t* str){
    if(!str){
        return 0;
    }
    str->data[str->capacity_m + 1] = NULL;
    return str->data;
}


