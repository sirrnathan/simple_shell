#include "shell.h"

/**
 *copy_string - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the copied string
 */
char *copy_string(char *dest, char *src, int n)
{
	int i, j;
	char *new_dest = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (new_dest);
}

/**
 *concatenate_strings - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the maximum amount of bytes to be used
 *Return: the concatenated string
 */
char *concatenate_strings(char *dest, char *src, int n)
{
	int i, j;
	char *new_dest = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (new_dest);
}

/**
 *find_character - locates a character in a string
 *@str: the string to be searched
 *@c: the character to be found
 *Return: (str) a pointer to the memory area str
 */
char *find_character(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
