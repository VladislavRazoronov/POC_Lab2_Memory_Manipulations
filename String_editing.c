#include <stdio.h>
#include "My_strings.h"

int my_str_free(my_string_t* str){
    /*
    * Frees memory used by given my_string
    * @param my_string_t* str my_string that will be used
    */
    if (str){
        free(str->data);
    }
    free(str);
    return 0;
}

int my_str_reserve(my_string_t* str, size_t buf_size){
    /*
    * Reserves extra memory for my_string equal to given buffer size
    * if the given size is smaller does nothing
    * @param my_string_t* str my_string that will be used
    * @param size_t buf_size The new capacity of my_string
    */
    if(str == NULL){
        return NULL_PTR_ERROR;
    }
    if(buf_size > str->capacity_m){
        char* new_data = malloc(buf_size + 1);
        if(new_data == NULL){
            return MEMORY_ALLOCATION_ERR;
        }
        for(int i = 0; i < str->capacity_m; i++){
            new_data[i] = str->data[i];
        }
        str->capacity_m = buf_size;
        str->data = new_data;
    }
    return 0;
}

int my_str_resize(my_string_t* str, size_t new_size, char sym){
    /*
    * Resizes given my_string to given size, and fills all exess
    * space with given char
    * @param my_string_t* str my_string that will be used
    * @param size_t new_size The new size of my_string
    * @param char sym The char to fill my_string if new size is bigger
    */
    if(str == NULL){
        return NULL_PTR_ERROR;
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

int my_str_insert_cstr(my_string_t* str, char* word){
    /*
    * Inserts given cstring at end of my_string and resizes
    * it if needed.
    * @param my_string_t* str my_string that will be used
    * @param char* word cstring to add to my_string
    */
    if(!str || !word){
        return NULL_PTR_ERROR;
    }
    for(int i = 0; i < len(word); i++){
        if(str->size_m > str->capacity_m){
            int res = my_str_reserve(str, str->capacity_m*2);
            if(res != 0){
                return res;
            }
        }
        str->data[str->size_m] = word[i];
        str->size_m += 1;
    }
    return 0;
}

int my_str_copy(const my_string_t* from,  my_string_t* to, int reserve){
    /*
    * copies symbols from first my_string to other my_string
    * @param const my_string_t* from my_string that will be copied
    * @param my_string_t* to my_string that from will be copied into
    * @param int reserve If bigger than 0 also fills to with zeroes
    */
    if(from == NULL, to == NULL){
        return NULL_PTR_ERROR;
    }
    if(reserve){
        my_str_resize(to, from->capacity_m, '0');
    }
    return 0;
}

int my_str_popback(my_string_t* str){
    /*
    * Removes last element from my_string
    * @param my_string_t* str my_string that will be used
    */
    if(!str){
        return NULL_PTR_ERROR;
    }
    if(str->size_m <1){
        return 0;
    }
    str->size_m -= 1;
}