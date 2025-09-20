#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "onegin.h"

void write_text(char** lines, const char* outfile_name, file_data* poem_info)
{
    assert(lines != NULL);

    FILE* file = fopen(outfile_name, "w");
    for (int i = 0; i < poem_info->num_lines; i++)
    {
            fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);
    return;
}
