#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#include "onegin.h"

char** read_text(const char* filename, file_data* poem_info)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        printf("Reading error\n");
        return 0;
    }

    long int file_size = chek_file_size(file);
    // printf("%s:%d: %s(): file_size = %d\n", __FILE__, __LINE__, __func__, file_size);

    poem_info->buffer_ptr = (char*)calloc(file_size + 1, sizeof(char));
    if (!poem_info->buffer_ptr)
    {
        fclose(file);
        return NULL;
    }

    poem_info->read_size = fread(poem_info->buffer_ptr, sizeof(char), file_size, file);

    fclose(file);

    poem_info->buffer_ptr[poem_info->read_size] = '\0';

    poem_info->num_lines = check_n_lines(poem_info);
    // printf("%s:%d: %s(): file_size = %d\n", __FILE__, __LINE__, __func__, *num_lines);

    return make_ptr_massive(poem_info);

}

char** make_ptr_massive(file_data* poem_info)
{
    assert(poem_info->buffer_ptr != NULL);

    char** lines = (char**)calloc(poem_info->num_lines, sizeof(char*));
    if (!lines)
    {
        free(poem_info->buffer_ptr);
        return NULL;
    }

    int line_index = 0;
    char* start_str = poem_info->buffer_ptr;

    for (size_t i = 0; i < poem_info->read_size; i++)
    {
        if (poem_info->buffer_ptr[i] == '\n')
        {
            poem_info->buffer_ptr[i] = '\0';
            lines[line_index++] = start_str;
            start_str = &poem_info->buffer_ptr[i+1];
        }
    }

    return lines;
}

long int chek_file_size(FILE* file)
{
    struct stat file_info = {};
    int fd = fileno(file);
    if (fstat(fd, &file_info)== -1)
    {
        printf("ERROR: check number of lines incorrect\n");
        exit(EXIT_FAILURE);
    }  //todo check return value

    return file_info.st_size;
}

int check_n_lines(file_data* poem_info)
{

    int n_lines = 0;
    char* buf_ptr = strchr(poem_info->buffer_ptr, '\n');

    while (buf_ptr != NULL)
    {
        n_lines += 1;
        buf_ptr = strchr(buf_ptr + 1, '\n');
    }

    return n_lines;
}

