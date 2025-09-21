#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "onegin.h"

void my_bubble(string_data* lines, file_data* poem_info)
{
    assert(lines != NULL);

    for (int i = 0; i < poem_info->num_lines - 1; i++)
    {
        for (int j = 0; j < poem_info->num_lines - (i+1); j++)
        {
            if (is_sorted_str(lines[j].line_ptr, lines[j+1].line_ptr) > 0)
            {
                swap(lines, j);
            }
        }
    }
}

void swap(string_data* lines, int index)
{
    assert(lines != NULL);

    string_data reserve = lines[index];
    lines[index] = lines[index+1];
    lines[index+1] = reserve;

    return;
}

int is_sorted_str(char* str_1, char* str_2)
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

        return tolower(*str_1) - tolower(*str_2);
    }

    return true;
}

int reverse_compare_wrapper(const void* a, const void* b)
{
    const string_data* struct_1 = (const string_data*)a;
    const string_data* struct_2 = (const string_data*)b;

    return compare_reverse_strings(*struct_1, *struct_2);
}

int compare_reverse_strings(string_data struct_1, string_data struct_2)
{
    const char* ptr_1 = struct_1.line_ptr + struct_1.line_len - 1;
    const char* ptr_2 = struct_2.line_ptr + struct_2.line_len - 1;

    const char* start_1 = struct_1.line_ptr;
    const char* start_2 = struct_2.line_ptr;

    while (ptr_1 >= start_1 && ptr_2 >= start_2)
    {
        while (ptr_1 >= start_1 && !isalpha(*ptr_1) && !isblank(*ptr_1))
        {
            ptr_1--;
        }

        while (ptr_2 >= start_2 && !isalpha(*ptr_2) && !isblank(*ptr_2))
        {
            ptr_2--;
        }

        if (ptr_1 < start_1 && ptr_2 < start_2)
            return 0;

        if (ptr_1 < start_1)
            return -1;

        if (ptr_2 < start_2)
            return 1;

        if (*ptr_1 != *ptr_2)
        {
            return (tolower(*ptr_1) < tolower(*ptr_2)) ? -1 : 1;
        }

        ptr_1--;
        ptr_2--;
    }

    return 0;
}
