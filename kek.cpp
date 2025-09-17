#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>

char** read_text(const char* filename, int* num_lines);

char** make_ptr_massive(char* buffer, int num_lines, size_t read_size);

void write_text(char** lines, const char* outfile_name, int num_lines);

void my_bubble(char** lines, int num_lines);
void swap(char** lines, int index);

bool is_sorted_str(char* str_1, char* str_2);
bool compare_char(char ch_1, char ch_2);

int main(void)
{
    int num_lines = 0;
    char** lines = read_text("Eugene_Onegin.txt", &num_lines);

    my_bubble(lines, num_lines);

    write_text(lines, "Onegin_done.txt", num_lines);
    free(lines[0]);
    free(lines);
    return 0;
}

char** read_text(const char* filename, int* num_lines)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        printf("Reading error\n");
        return 0;
    }

    struct stat file_info;
    int fd = fileno(file);
    if (fstat(fd, &file_info) == -1) {
        fclose(file);
        return NULL;
    }
    long int file_size = file_info.st_size;

    char* buffer = (char*)calloc(file_size + 1, sizeof(char));
    if (!buffer) {
        fclose(file);
        return NULL;
    }

    size_t read_size = fread(buffer, 1, file_size, file);
    fclose(file);
    buffer[read_size] = '\0';

    *num_lines = 0;
    for (size_t i = 0; i < read_size; i++) {
        if (buffer[i] == '\n')
        {
            (*num_lines)++;
        }
    }

    if (read_size > 0 && buffer[read_size-1] != '\0')
    {
        buffer[read_size] = '\0';
    }

    return make_ptr_massive(buffer, *num_lines, read_size);

}


void write_text(char** lines, const char* outfile_name, int num_lines)
{
    FILE* file = fopen(outfile_name, "w");
    for (int i = 0; i < num_lines; i++)
    {
            fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);
    return;
}

char** make_ptr_massive(char* buffer, int num_lines, size_t read_size)
{

    char** lines = (char**)calloc(num_lines, sizeof(char*));
    if (!lines)
    {
        free(buffer);
        return NULL;
    }

    int line_index = 0;
    char* start_str = buffer;

    for (size_t i = 0; i < read_size; i++)
    {
        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
            lines[line_index++] = start_str;
            start_str = &buffer[i+1];
        }
    }

    return lines;
}


void my_bubble(char** lines, int num_lines)
{
    for (int i = 0; i < num_lines; i++)
    {
        for (int j = 0; j < num_lines - (i+1); j++)
        {
            if (!is_sorted_str(lines[j], lines[j+1]))
            {
                swap(lines, j);
            }
        }
    }
}

void swap(char** lines, int index)
{
    char* reserve = lines[index];
    lines[index] = lines[index+1];
    lines[index+1] = reserve;

    return;
}

bool is_sorted_str(char* str_1, char* str_2)
{
    assert(str_1 != NULL);
    assert(str_2 != NULL);

    while (*str_1 != '\0' && *str_2 != '\0')
    {
        if (!isalpha(*str_1))
        {
            str_1++;
            continue;
        }

        if (!isalpha(*str_1))
        {
            str_2++;
            continue;
        }

        if (tolower(*str_1) == tolower(*str_2))
        {
            str_1++;
            str_2++;
            continue;
        }

        return compare_char((char)tolower(*str_1), (char)tolower(*str_2));

    }

    return true;
}

bool compare_char(char ch_1, char ch_2)
{
    if (ch_1 < ch_2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
