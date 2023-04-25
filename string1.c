#include "shell.h"

/**
 *copy_string - copies a string to destination
 *@destination: the destination string to be copied to
 *@source: the source string
 *@n_bytes: the number of bytes to be copied
 *Return: the concatenated string
 */
char *copy_string(char *destination, char *source, int n_bytes)
{
	int i, j;
	char *result = destination;

	i = 0;
	while (source[i] != '\0' && i < n_bytes - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < n_bytes)
	{
		j = i;
		while (j < n_bytes)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (result);
}

/**
 *concat_strings - concatenates two strings
 *@string1: the first string
 *@string2: the second string
 *@n_bytes: the number of bytes to be used
 *Return: the concatenated string
 */
char *concat_strings(char *string1, char *string2, int n_bytes)
{
	int i, j;
	char *result = string1;

	i = 0;
	j = 0;
	while (string1[i] != '\0')
		i++;
	while (string2[j] != '\0' && j < n_bytes)
	{
		string1[i] = string2[j];
		i++;
		j++;
	}
	if (j < n_bytes)
		string1[i] = '\0';
	return (result);
}

/**
 *find_character - locates a character in a string
 *@string: the string to be parsed
 *@character: the character to look for
 *Return: (string) a pointer to the memory area string
 */
char *find_character(char *string, char character)
{
	do {
		if (*string == character)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}
