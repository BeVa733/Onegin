#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "onegin.h"

//WSL download

int main(void)
{
    int num_lines = 0;
    // file_data poem_info = {}
    char** lines = read_text("Eugene_Onegin.txt", &num_lines);

    my_bubble(lines, num_lines);

    write_text(lines, "Onegin_done.txt", num_lines); //struct

    free(lines[0]); //buff
    free(lines);//null
    return 0;
}
