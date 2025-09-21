#ifndef ONEGIN_H
#define ONEGIN_H

struct file_data
{
    char* buffer_ptr;
    int num_lines;
    size_t read_size;
};

struct string_data
{
    char* line_ptr;
    int line_len;
};

string_data* read_text(const char* filename, file_data* poem_info);

string_data* make_struct_massive(file_data* poem_info);

long int chek_file_size(FILE* file);
int check_n_lines(file_data* poem_info);

void write_text(string_data* lines, FILE* file, file_data* poem_info);
void write_original(FILE* file, file_data* poem_info);

void my_bubble(string_data* lines, file_data* poem_info);
void swap(string_data* lines, int index);

bool is_sorted_str(char* str_1, char* str_2);
int compare_wrapper(const void* a, const void* b);
int compare_reverse_strings(string_data str1, string_data str2);


#endif
