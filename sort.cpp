#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

#include "onegin.h"

void my_bubble(char** lines, int num_lines)
{
    assert(lines != NULL);

    for (int i = 0; i < num_lines - 1; i++)
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
    assert(lines != NULL);

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
        if (!(isalpha(*str_1) || isblank(*str_1)))
        {
            str_1++;
            continue;
        }

        if (!(isalpha(*str_2) || isblank(*str_2)))
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
    return (ch_1 < ch_2);
}
