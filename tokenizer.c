#include "shell.h"

/**
 *copy_string - copies a string
 *@destination: the destination string to be copied to
 *@source: the source string
 *@num: the number of characters to be copied
 *Return: the concatenated string
 */
char *copy_string(char *destination, char *source, int num)
{
	int i, j;
	char *result = destination;

	i = 0;
	while (source[i] != '\0' && i < num - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < num)
	{
		j = i;
		while (j < num)
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
 *@num: the number of bytes to be maximally used
 *Return: the concatenated string
 */
char *concat_strings(char *string1, char *string2, int num)
{
	int i, j;
	char *result = string1;

	i = 0;
	j = 0;
	while (string1[i] != '\0')
		i++;
	while (string2[j] != '\0' && j < num)
	{
		string1[i] = string2[j];
		i++;
		j++;
	}
	if (j < num)
		string1[i] = '\0';
	return (result);
}

/**
 *find_char - locates a character in a string
 *@string: the string to be parsed
 *@character: the character to look for
 *Return: (string) a pointer to the memory area string
 */
char *find_char(char *string, char character)
{
	do {
		if (*string == character)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}
