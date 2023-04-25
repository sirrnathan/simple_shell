#include "shell.h"

/**
 * copy_string - copies a string
 * @destination: the destination string to be copied to
 * @source: the source string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
 */
char *copy_string(char *destination, char *source, int n)
{
	int i, j;
	char *result = destination;

	i = 0;
	while (source[i] != '\0' && i < n - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (result);
}

/**
 * concatenate_strings - concatenates two strings
 * @string1: the first string
 * @string2: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *concatenate_strings(char *string1, char *string2, int n)
{
	int i, j;
	char *result = string1;

	i = 0;
	j = 0;
	while (string1[i] != '\0')
		i++;
	while (string2[j] != '\0' && j < n)
	{
		string1[i] = string2[j];
		i++;
		j++;
	}
	if (j < n)
		string1[i] = '\0';
	return (result);
}

/**
 * find_character - locates a character in a string
 * @string: the string to be parsed
 * @character: the character to look for
 * Return: (string) a pointer to the memory area string
 */
char *find_character(char *string, char character)
{
	do {
		if (*string == character)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}
