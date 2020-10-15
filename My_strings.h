/*Error codes */
const int NOT_FOUND_CODE = -1, MEMORY_ALLOCATION_ERR = -2, RANGE_ERR = -3, IO_READ_ERR = -4;
const int IO_WRITE_ERR = -5, NULL_PTR_ERROR = -8, BUFF_SIZE_ERR = -9;

/*Main class*/
typedef struct {
    size_t capacity_m;
    size_t size_m;
    char* data;
} my_string_t;

/*Function declarations*/
int my_string_t_create(my_string_t* str, size_t buf_size);

int my_str_free(my_string_t* str);

size_t my_str_size(const my_string_t* str);

size_t my_str_capacity(const my_string_t* str);

int my_str_empty(const my_string_t* str);

int my_str_getc(const my_string_t* str, size_t index);

const char* my_str_get_cstr(my_string_t* str);

int my_str_resize(my_string_t* str, size_t new_size, char sym);

int my_str_copy(const my_string_t* from,  my_string_t* to, int reserve);

int my_str_popback(my_string_t* str);

int my_str_insert_cstr(my_string_t* str, char* word);

int my_str_read_file(my_string_t* str, FILE* file);

int my_str_read(my_string_t* str);

int my_str_read_file_delim(my_string_t* str, FILE* file, char delimiter);

int my_str_write(const my_string_t* str);

int my_str_write_file(const my_string_t* str, FILE* file);

int my_str_shrink_to_fit(my_string_t* str);

int my_str_clear(my_string_t* str);

int my_str_insert_c(my_string_t* str, char c, size_t pos);

int my_str_insert(my_string_t* str, const my_string_t* from, size_t pos);

int my_str_append(my_string_t* str, const my_string_t* from);

int my_str_append_cstr(my_string_t* str, const char* from);

int my_str_append_c(my_string_t* str, char c);

int my_str_substr(const my_string_t* from, my_string_t* to, size_t beg, size_t end);

int my_str_substr_cstr(const my_string_t* from, char* to, size_t beg, size_t end);

int my_str_erase(my_string_t* str, size_t beg, size_t end);

int my_str_cmp_cstr(const my_string_t* str1, const char* cstr2);

int my_str_cmp(const my_string_t* str1, const my_string_t* str2);

size_t my_str_find_if(const my_string_t* str, size_t beg, int (*predicat)(int));

size_t my_str_find_c(const my_string_t* str, char tofind, size_t from);

size_t my_str_find(const my_string_t* str, const my_string_t* tofind, size_t from);