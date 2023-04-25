#include "shell.h"

/**
 *copy_string - copies a string
 *@destination: the destination string to be copied to
 *@source: the source string
 *@count: the amount of characters to be copied
 *Return: the concatenated string
 */
char *copy_string(char *destination, char *source, int count)
{
	int i, j;
	char *s = destination;

	i = 0;
	while (source[i] != '\0' && i < count - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < count)
	{
		j = i;
		while (j < count)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 *concat_strings - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@count: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *concat_strings(char *dest, char *src, int count)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < count)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < count)
		dest[i] = '\0';
	return (s);
}

/**
 *find_char - locates a character in a string
 *@str: the string to be parsed
 *@ch: the character to look for
 *Return: (str) a pointer to the memory area str
 */
char *find_char(char *str, char ch)
{
	do {
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
