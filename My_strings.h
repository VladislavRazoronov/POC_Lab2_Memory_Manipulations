const int NOT_FOUND_CODE = -1, MEMORY_ALLOCATION_ERR = -2, RANGE_ERR = -3, IO_READ_ERR = -4;
const int IO_WRITE_ERR = -5, NULL_PTR_ERROR = -8, BUFF_SIZE_ERR = -9;

typedef struct {
    size_t capacity_m;
    size_t size_m;
    char* data;
} my_string_t;

int my_string_t_create(my_string_t* str, size_t buf_size);

int my_str_free(my_string_t* str);

size_t my_str_size(const my_string_t* str);

size_t my_str_capacity(const my_string_t* str);

int my_str_empty(const my_string_t* str);

int my_str_getc(const my_string_t* str, size_t index);

const char* my_str_get_cstr(my_string_t* str);

int my_str_resize(my_string_t* str, size_t new_size, char sym);

int my_str_copy(const my_string_t* from,  my_string_t* to, int reserve);