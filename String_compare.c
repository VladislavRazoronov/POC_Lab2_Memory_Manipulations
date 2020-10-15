#include <stdio.h>
#include "My_strings.h"

//LD
int my_str_cmp(const my_string_t* str1, const my_string_t* str2)  //NEW
{
    if ((str1 == NULL) || (str2 == NULL)){
        return NOT_FOUND_CODE;
    }
    if (my_str_size(str1) < my_str_size(str2)){
        return -1;
    }
    if (my_str_size(str1) > my_str_size(str2)){
        return 1;
    }
    for (size_t i = 0; i<my_str_size(str1); i++){
        if ((int)str1->data[i] < (int) str2->data[i]){
            return -1;
        }
        if ((int)str1->data[i] > (int) str2->data[i]){
            return 1;
        }
    }
    return 0;
}

//LD
int my_str_cmp_cstr(const my_string_t* str1, const char* cstr2)  // NEW REMAKE
{
    my_string_t* str2;
    my_str_create(str2,strlen(cstr2));
    my_str_from_cstr(str2, cstr2, strlen(cstr2));
   return my_str_cmp( str1, str2);
}