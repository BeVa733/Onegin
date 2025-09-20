#ifndef ONEGIN_H
#define ONEGIN_H

struct file_data
{
    char* buffer_ptr;
    int num_lines;
    size_t read_size;
};

char** read_text(const char* filename, file_data* poem_info);

char** make_ptr_massive(file_data* poem_info);

long int chek_file_size(FILE* file);
int check_n_lines(file_data* poem_info);

void write_text(char** lines, const char* outfile_name, file_data* poem_info);

void my_bubble(char** lines, file_data* poem_info);
void swap(char** lines, int index);

bool is_sorted_str(char* str_1, char* str_2);
bool compare_char(char ch_1, char ch_2);

#endif
