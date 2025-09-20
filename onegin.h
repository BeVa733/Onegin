#ifndef ONEGIN_H
#define ONEGIN_H

//struct file_data
//{
//    char* buffer_ptr;
//    int num_lines;
//    size_t read_size;
//};

char** read_text(const char* filename, int* num_lines);

char** make_ptr_massive(char* buffer, int num_lines, size_t read_size);

long int chek_file_size(FILE* file);
int check_n_lines(char* buffer, size_t read_size);

void write_text(char** lines, const char* outfile_name, int num_lines);

void my_bubble(char** lines, int num_lines);
void swap(char** lines, int index);

bool is_sorted_str(char* str_1, char* str_2);
bool compare_char(char ch_1, char ch_2);

#endif
