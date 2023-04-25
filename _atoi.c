#include "shell.h"

/**
 * is_shell_interactive - function that checks whether the
 *  shell is in interactive mode
 * @info: pointer to info_t struct
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */

int is_shell_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_character_lim - checks if a character is a delimiter
 * @d: character to check
 * @lim: delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_character_lim(char d, char *lim)
{
	while (*lim)
	{
		if (*lim++ == d)
			return (1);
	}
	return (0);
}

/**
 * is_character_d - checks if a character is alphabetic
 * @d: character to check
 *
 * Return: 1 if d is alphabetic, 0 otherwise
 */
int is_character_d(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * string_to_integer - converts a string to an integer
 * @s: string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */
int string_to_integer(char *s)
{
	int index, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (index = 0; s[index] != '\0' && flag != 2; index++)
	{
		if (s[index] == '-')
			sign *= -1;

		if (s[index] >= '0' && s[index] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
