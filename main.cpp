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

    char** lines = read_text("Eugene_Onegin.txt", &poem_info);

    my_bubble(lines, &poem_info);

    write_text(lines, "Onegin_done.txt", &poem_info); //struct

    free(poem_info.buffer_ptr); //buff
    free(lines);//null
    return 0;
}
