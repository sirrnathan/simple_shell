#include "shell.h"

/**
 *copy_string - copies a string
 *@dest_string: the destination string to be copied to
 *@src_string: the source string
 *@n_chars: the amount of characters to be copied
 *Return: the concatenated string
 */
char *copy_string(char *dest_string, char *src_string, int n_chars)
{
	int i, j;
	char *str = dest_string;

	i = 0;
	while (src_string[i] != '\0' && i < n_chars - 1)
	{
		dest_string[i] = src_string[i];
		i++;
	}
	if (i < n_chars)
	{
		j = i;
		while (j < n_chars)
		{
			dest_string[j] = '\0';
			j++;
		}
	}
	return (str);
}

/**
 *concat_strings - concatenates two strings
 *@dest_string: the first string
 *@src_string: the second string
 *@n_bytes: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *concat_strings(char *dest_string, char *src_string, int n_bytes)
{
	int i, j;
	char *str = dest_string;

	i = 0;
	j = 0;
	while (dest_string[i] != '\0')
		i++;
	while (src_string[j] != '\0' && j < n_bytes)
	{
		dest_string[i] = src_string[j];
		i++;
		j++;
	}
	if (j < n_bytes)
		dest_string[i] = '\0';
	return (str);
}

/**
 *find_character - locates a character in a string
 *@str: the string to be parsed
 *@char_to_find: the character to look for
 *Return: (str) a pointer to the memory area str
 */
char *find_character(char *str, char char_to_find)
{
	do {
		if (*str == char_to_find)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
