#include "shell.h"

/**
 * _str_cpy - copies a string
 * @target: the destination string to be copied to
 * @source: the source string
 * @num_chars: the amount of characters to be copied
 * Return: the concatenated string
 */
char *_str_cpy(char *target, char *source, int num_chars)
{
    int i, j;
    char *s = target;

    i = 0;
    while (source[i] != '\0' && i < num_chars - 1)
    {
        target[i] = source[i];
        i++;
    }
    if (i < num_chars)
    {
        j = i;
        while (j < num_chars)
        {
            target[j] = '\0';
            j++;
        }
    }
    return (s);
}

/**
 * _str_cat - concatenates two strings
 * @target: the first string
 * @source: the second string
 * @num_chars: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *_str_cat(char *target, char *source, int num_chars)
{
    int i, j;
    char *s = target;

    i = 0;
    j = 0;
    while (target[i] != '\0')
        i++;
    while (source[j] != '\0' && j < num_chars)
    {
        target[i] = source[j];
        i++;
        j++;
    }
    if (j < num_chars)
        target[i] = '\0';
    return (s);
}

/**
 * _str_chr - locates a character in a string
 * @str: the string to be parsed
 * @c: the character to look for
 * Return: a pointer to the memory area `str`
 */
char *_str_chr(char *str, char c)
{
    do {
        if (*str == c)
            return (str);
    } while (*str++ != '\0');

    return (NULL);
}
