#include <stdio.h>
#include "My_strings.h"

int my_str_free(my_string_t* str){
    /*
    * Frees memory used by given my_string(VR)
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
    * if the given size is smaller does nothing(VR)
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
    * space with given char(VR)
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
    * it if needed.(VR)
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

/*
* copies symbols from first my_string to other my_string(VR)
* @param const my_string_t* from my_string that will be copied
* @param my_string_t* to my_string that from will be copied into
* @param int reserve If bigger than 0 also fills to with zeroes
*/
int my_str_copy(const my_string_t* from,  my_string_t* to, int reserve){
    
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
    * Removes last element from my_string(VR)
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

int my_str_shrink_to_fit(my_string_t* str){
    /*
    * Shrinks string's buffer to string size
    * @param my_string_t* str String that will be shrunk
    */
    if (!str){
        return NULL_PTR_ERROR;
    }
    if(my_str_reserve(str, str->size_m) > 0){
        return 0;
    }
    else{
        return MEMORY_ALLOCATION_ERR;
    }
}

//LD
int my_str_clear(my_string_t* str){
    if(str == NULL){
    return NULL_PTR_ERROR;
    }
    str->size_m = 0;
    return 0;
}

//LD
int my_str_insert_c(my_string_t* str, char c, size_t pos){
    if(str == NULL){
    return NULL_PTR_ERROR;
    }
    if (str->size_m+1 < my_str_capacity(str)){
        my_str_reserve(str, my_str_capacity(str));
    }
    if (pos > str->size_m){
        return MEMORY_ALLOCATION_ERR;
    }
    char elem = c;
    char new_elem = c;
    for (size_t i=pos; i<=str->size_m;i++){
        elem = str->data[i];
        str->data[i] = new_elem;
        new_elem = elem;
    }
    return 0;
}

//LD
int my_str_insert(my_string_t* str, const my_string_t* from, size_t pos){
    if(str == NULL || from==NULL){
    return NULL_PTR_ERROR;
    }
    for (size_t i=0; i<from->size_m;i++){
        my_str_insert_c(str, from->data[i], pos+i);
    }
}

//LD
int my_str_append(my_string_t* str, const my_string_t* from)
{
    if(str == NULL || from==NULL){
    return NULL_PTR_ERROR;
    }
    for(size_t i=0; i<from->size_m; i++){
        my_str_append_c(str, from->data[i]);
    }
    return 0;
}

//LD
int my_str_append_cstr(my_string_t* str, const char* from)
{
    my_string_t* str2;
    my_str_create(str2, strlen(from));
    my_str_from_cstr(str2, from, strlen(from));
    my_str_append(str, str2);
}

//LD
int my_str_append_c(my_string_t* str, char c)
{
    if(str == NULL){
    return NULL_PTR_ERROR;
    }
    if (str->size_m+1<str->capacity_m){
        my_str_reserve(str, (size_t)1);
    }
    str->size_m++;
    str->data[str->size_m-1]=c;
    return 0;
}

//LD
int my_str_substr(const my_string_t* from, my_string_t* to, size_t beg, size_t end)
{
    if(!from || !to){
    return NULL_PTR_ERROR;
    }
    if (beg>from->size_m){
        return RANGE_ERR;
    }
    if (end > from->size_m){
        end = from->size_m;
    }
    for (size_t i=beg; i<end; i++){
        my_str_append_c(to, from->data[i]);
    }
    return 0;
}

//LD
int my_str_substr_cstr(const my_string_t* from, char* to, size_t beg, size_t end)
{
    my_string_t* new_str;
    my_str_create(new_str, end-beg);
    my_str_substr(from, new_str, beg, end);
    to = my_str_get_cstr(new_str);
}

//LD
int my_str_erase(my_string_t* str, size_t beg, size_t end)
{
    if(!str){
    return NULL_PTR_ERROR;
    }
    if (beg>str->size_m){
        return RANGE_ERR;
    }
    if (end>=str->size_m){
        str->size_m = beg;
        return 0;
    }
    my_string_t* new_str;
    my_str_create(new_str, str->size_m-end);
    my_str_substr(str, new_str, end, str->size_m);
    str->size_m = beg;
    my_str_append(str, new_str);
    return 0;
}