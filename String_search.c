#include <stdio.h>
#include "My_strings.h"

//LD
size_t my_str_find(const my_string_t* str, const my_string_t* tofind, size_t from) // NEW
{
    if (tofind == NULL){
        return NOT_FOUND_CODE;
    }
    if ((my_str_empty(tofind))||(my_str_size(tofind) > my_str_size(str))){
        return (size_t)(-1);
    }
    for (size_t i = 0; i<my_str_size(str)-my_str_size(tofind); i++){
        if (str->data[i] == tofind->data[0]){
            size_t j = 0;
            size_t k = i;
            while ((j<my_str_size(tofind)) && (str->data[k] == tofind->data[j])) {
                j++;
                k++;
            }
            if (j == my_str_size(tofind)){
                return i;
            }
        }
    }
    return (size_t)(-1);
}

//LD
size_t my_str_find_c(const my_string_t* str, char tofind, size_t from) //NEW
{
    if (str == NULL){
        return NOT_FOUND_CODE;
    }
    if (from >= my_str_size(str)){
        return (size_t)(-1);
    }
    for (size_t i = from; i<my_str_size(str); i++){
        if (str->data[i] == tofind){
            return 0;
        }
    }
    return (size_t)(-1);
}

//LD
size_t my_str_find_if(const my_string_t* str, size_t beg, int (*predicat)(int))  //NEW
{
    if (str == NULL){
        return NOT_FOUND_CODE;
    }
    if (beg >= my_str_size(str)){
        return (size_t)(-1);
    }
    if (predicat == NULL){
        return (size_t)(-1);
    }
    for (size_t i = beg; i<my_str_size(str); i++){
        if (predicat((int)str->data[i])){
            return i;
        }
    }
    return (size_t)(-1);
}
