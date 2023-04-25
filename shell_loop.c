#include "shell.h"

/**
 *copy_string - copies a string
 *@dest_str: the destination string to be copied to
 *@src_str: the source string
 *@num_chars: the number of characters to be copied
 *Return: the concatenated string
 */
char *copy_string(char *dest_str, char *src_str, int num_chars)
{
    int i, j;
    char *str_ptr = dest_str;

    i = 0;
    while (src_str[i] != '\0' && i < num_chars - 1)
    {
        dest_str[i] = src_str[i];
        i++;
    }
    if (i < num_chars)
    {
        j = i;
        while (j < num_chars)
        {
            dest_str[j] = '\0';
            j++;
        }
    }
    return (str_ptr);
}

/**
 *concatenate_strings - concatenates two strings
 *@first_str: the first string
 *@second_str: the second string
 *@max_bytes: the maximum number of bytes to be used
 *Return: the concatenated string
 */
char *concatenate_strings(char *first_str, char *second_str, int max_bytes)
{
    int i, j;
    char *str_ptr = first_str;

    i = 0;
    j = 0;
    while (first_str[i] != '\0')
        i++;
    while (second_str[j] != '\0' && j < max_bytes)
    {
        first_str[i] = second_str[j];
        i++;
        j++;
    }
    if (j < max_bytes)
        first_str[i] = '\0';
    return (str_ptr);
}

/**
 *find_character - locates a character in a string
 *@str_ptr: the string to be parsed
 *@char_to_find: the character to look for
 *Return: (str_ptr) a pointer to the memory area str_ptr
 */
char *find_character(char *str_ptr, char char_to_find)
{
    do {
        if (*str_ptr == char_to_find)
            return (str_ptr);
    } while (*str_ptr++ != '\0');

    return (NULL);
}
