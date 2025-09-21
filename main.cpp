#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "onegin.h"

//WSL download

int main(void)
{
    file_data poem_info =
    {
        .buffer_ptr = NULL,
        .num_lines = 0,
        .read_size = 0
    };

    string_data* lines = read_text("Eugene_Onegin.txt", &poem_info);

    FILE* file = fopen("Onegin_done.txt", "w");

    my_bubble(lines, &poem_info);
    write_text(lines, file, &poem_info);

    qsort(lines, poem_info.num_lines, sizeof(string_data), compare_wrapper);
    write_text(lines, file, &poem_info);

    write_original(file, &poem_info);

    fclose(file);

    free(poem_info.buffer_ptr);
    poem_info.buffer_ptr = NULL;
    free(lines);
    lines = NULL;

    return 0;
}
