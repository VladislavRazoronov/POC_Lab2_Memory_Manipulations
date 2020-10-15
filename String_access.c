#include "My_strings.h"
#include <stdio.h>

int my_str_getc(const my_string_t* str, size_t index)
{
    /*
    * Gets char from a given index(LD)
    * @param my_string_t* str String to get char from
    * @param size_t index index of a required string
    */
    if(index > str->size_m){
        return RANGE_ERR;
    }
    if(!str){
        return NOT_FOUND_CODE;
    }
    return str->data[index];
}

int my_str_putc(my_string_t* str, size_t index, char c)
{
    /*
    * Puts given char at given index in string
    * @param my_string_t* str string to insert in
    * @param size_t index index of inserted char
    * @param char c Char that needs to be inserted
    */
    if (!str){
        return NULL_PTR_ERROR;
    }
    if (index > my_str_size(str)){
        return RANGE_ERR;
    }
    str->data[index] = c;
    return 0;
    // check later
}
