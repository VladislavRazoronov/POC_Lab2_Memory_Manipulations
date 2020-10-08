#include <stdio.h>
#include "My_strings.h"

int my_str_free(my_string_t* str){
    if (str){
        free(str->data);
    }
    free(str);
    return 0;
}

int my_str_reserve(my_string_t* str, size_t buf_size){
    if(str == NULL){
        return NOT_FOUND_CODE;
    }
    if(buf_size > str->capacity_m){
        char* new_data = malloc(buf_size + 1);
        for(int i = 0; i < str->capacity_m; i++){
            new_data[i] = str->data[i];
        }
        str->capacity_m = buf_size;
        str->data = new_data;
    }
    return 0;
}

int my_str_resize(my_string_t* str, size_t new_size, char sym){
    if(str == NULL){
        return NOT_FOUND_CODE;
    }
    if(new_size < str->size_m){
        str->size_m = new_size;
        return 0;
    }
    else if(new_size > str->capacity_m){
        my_str_reserve(str, new_size);
    }
    while(str->size_m < new_size){
        str->data[str->size_m] = sym;
        str->size_m++;
        }
    return 0;
}

int my_str_copy(const my_string_t* from,  my_string_t* to, int reserve){
    if(from == NULL, to == NULL){
        return -8;
    }
    if(reserve){
        my_str_resize(to, from->capacity_m, '0');
    }
    return 0;
}