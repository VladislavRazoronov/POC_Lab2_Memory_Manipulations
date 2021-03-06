#include <stdio.h>
#include <string.h>
#include "My_strings.h"

int my_string_t_create(my_string_t* str, size_t buf_size){
    /*
    * A function to create my_string with given buffer size(VR)
    * @param my_string_t* str my_string that will be used
    * @param size_t buf_size The size of it's buffer
    */
    if(!str){
        return NULL_PTR_ERROR;
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
    /*
    * Returns the size of my_string given (VR)
    * @param my_string_t* str my_string that will be used
    */
    if(!str){
        return 0;
    }
    return str->size_m;
}

size_t my_str_capacity(const my_string_t* str){
    /*
    * Returns maximum capacity of my_string given(VR)
    * @param my_string_t* str my_string that will be used
    */
    if(!str){
        return 0;
    }
    return str->capacity_m;
}

int my_str_empty(const my_string_t* str){
    /*
    * Returns true if given my_string is emplty, else returns false(VR)
    * @param my_string_t* str my_string that will be used
    */
    if(!str){
        return NULL_PTR_ERROR;
    }
    return str->size_m==0;
}

int my_str_getc(const my_string_t* str, size_t index){
    /*
    * Returns char at given indes in str(VR)
    * @param my_string_t* str my_string that will be used
    * @param size_t index Index of required element
    */
    if(index > str->size_m){
        return RANGE_ERR;
    }
    if(!str){
        return NULL_PTR_ERROR;
    }
    return str->data[index];
}

const char* my_str_get_cstr(my_string_t* str){
    /*
    * Returns char* representation of given my_string(VR)
    * @param my_string_t* str my_string that will be used
    */
    if(!str){
        return 0;
    }
    str->data[str->capacity_m + 1] = NULL;
    return str->data;
}


