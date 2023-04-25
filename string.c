#include "shell.h"

/**
 *copy_str - copies a string
 *@dest_str: the destination string to be copied to
 *@src_str: the source string
 *@num_chars: the amount of characters to be copied
 *Return: the concatenated string
 */
char *copy_str(char *dest_str, char *src_str, int num_chars)
{
	int i, j;
	char *s = dest_str;

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
	return (s);
}

/**
 *concatenate_str - concatenates two strings
 *@first_str: the first string
 *@second_str: the second string
 *@num_bytes: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *concatenate_str(char *first_str, char *second_str, int num_bytes)
{
	int i, j;
	char *s = first_str;

	i = 0;
	j = 0;
	while (first_str[i] != '\0')
		i++;
	while (second_str[j] != '\0' && j < num_bytes)
	{
		first_str[i] = second_str[j];
		i++;
		j++;
	}
	if (j < num_bytes)
		first_str[i] = '\0';
	return (s);
}

/**
 *find_char - locates a character in a string
 *@str: the string to be parsed
 *@c: the character to look for
 *Return: (str) a pointer to the memory area str
 */
char *find_char(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
