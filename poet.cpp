#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "onegin.h"

void write_text(char** lines, const char* outfile_name, int num_lines)
{
    assert(lines != NULL);

    FILE* file = fopen(outfile_name, "w");
    for (int i = 0; i < num_lines; i++)
    {
            fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);
    return;
}
