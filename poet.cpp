#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "onegin.h"

void write_text(string_data* lines, FILE* file, file_data* poem_info)
{
    assert(lines != NULL);

    for (int i = 0; i < poem_info->num_lines; i++)
    {
        fprintf(file, "%s\n", lines[i].line_ptr);
    }

    fprintf(file, "\n\n\n-------------------------------------\n\n\n");

    return;
}

void write_original(FILE* file, file_data* poem_info)
{
    const char* str_ptr = poem_info->buffer_ptr;
    int cnt_chr = 0;
    for (int i = 0; i < poem_info->num_lines; i++)
    {
        fprintf(file, "%s\n", str_ptr);
        str_ptr = strchr(str_ptr, '\0') + 1;
    }

    return;
}
