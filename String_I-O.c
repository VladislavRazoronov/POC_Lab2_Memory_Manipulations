#include <stdio.h>
#include <stdlib.h>

#include "My_strings.h"

int my_str_read_file(my_string_t* str, FILE* file){
    if(file == NULL){
        return NULL_PTR_ERROR;
    }
    fseek(file, 0L, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);
    if(file_size < str->capacity_m){
        while(str->data[-1]!= EOF){
            if( !fgets(str->data, str->capacity_m - str->size_m, file)){
                return IO_READ_ERR;
            }
            str->size_m += file_size;
        }
        int my_str_popback(my_string_t* str);
    }
    else{
        while(str->data[-1] != EOF){
            if(str->capacity_m > str->size_m){
                size_t start = ftell(file);
                if(!fgets(str->data, str->capacity_m - str->size_m, file)){
                    return IO_READ_ERR;
                }
                size_t stop = ftell(file);
                str->size_m += stop - start;
            }
            else{
                my_str_reserve(str, str->capacity_m*2);
            }
        }
        
    }
    return 0;
}

int my_str_read(my_string_t* str){
    char* text = scanf("%s");
    return My_str_insert_cstr(str, text);
}

int my_str_read_file_delim(my_string_t* str, FILE* file, char delimiter);

int my_str_write_file(const my_string_t* str, FILE* file);

int my_str_write(const my_string_t* str);
