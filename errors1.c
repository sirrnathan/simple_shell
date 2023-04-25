#include "shell.h"

/**
 * str_to_int - converts a string to an integer
 * @str: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
int str_to_int(char *str)
{
	int i = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error_msg - prints an error message
 * @info: the parameter & return info struct
 * @error_str: string containing specified error type
 *
 * Return: void
 */
void print_error_msg(info_t *info, char *error_str)
{
	_eputs(info->filename);
	_eputs(": ");
	print_d(str_to_int(info->line_count), STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(error_str);
}

/**
 * print_decimal - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_decimal(int input, int fd)
{
	int (*write_char)(char) = _putchar;
	int i, count = 0;
	unsigned int absolute, current;

	if (fd == STDERR_FILENO)
		write_char = _eputchar;
	if (input < 0)
	{
		absolute = -input;
		write_char('-');
		count++;
	}
	else
		absolute = input;
	current = absolute;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (absolute / i)
		{
			write_char('0' + current / i);
			count++;
		}
		current %= i;
	}
	write_char('0' + current);
	count++;

	return (count);
}

/**
 * num_to_str - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *num_to_str(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always void
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
