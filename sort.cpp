#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

#include "onegin.h"

void my_bubble(string_data* lines, file_data* poem_info)
{
    assert(lines != NULL);

    for (int i = 0; i < poem_info->num_lines - 1; i++)
    {
        for (int j = 0; j < poem_info->num_lines - (i+1); j++)
        {
            if (!is_sorted_str(lines[j].line_ptr, lines[j+1].line_ptr))
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

bool is_sorted_str(char* str_1, char* str_2) //TODO ˜˜˜˜˜˜˜˜˜ ˜ int
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

        return tolower(*str_1) < tolower(*str_2);
    }

    return true;
}

int compare_wrapper(const void* a, const void* b)
{
    const string_data* str1 = (const string_data*)a;
    const string_data* str2 = (const string_data*)b;

    return compare_reverse_strings(*str1, *str2);
}

int compare_reverse_strings(string_data str1, string_data str2)
{
    const char* ptr1 = str1.line_ptr + str1.line_len - 1;
    const char* ptr2 = str2.line_ptr + str2.line_len - 1;

    const char* start1 = str1.line_ptr;
    const char* start2 = str2.line_ptr;

    while (ptr1 >= start1 && ptr2 >= start2)
    {
        while (ptr1 >= start1 && !isalpha(*ptr1) && !isblank(*ptr1))
        {
            ptr1--;
        }

        while (ptr2 >= start2 && !isalpha(*ptr2) && !isblank(*ptr2))
        {
            ptr2--;
        }

        if (ptr1 < start1 && ptr2 < start2)
            return 0;

        if (ptr1 < start1)
            return -1;

        if (ptr2 < start2)
            return 1;

        if (*ptr1 != *ptr2)
        {
            return (tolower(*ptr1) < tolower(*ptr2)) ? -1 : 1;
        }

        ptr1--;
        ptr2--;
    }

    if (ptr1 < start1 && ptr2 < start2)
        return 0;
}
