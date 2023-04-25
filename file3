#include "shell.h"

/**
 * print_history - displays the history list, one command by line, preceded
 *                 with line numbers, starting at 0.
 * @information: Structure containing potential arguments. Used to maintain
 *               constant function prototype.
 * Return: Always 0
 */
int print_history(information_t *information)
{
	print_list(information->history);
	return (0);
}

/**
 * remove_alias - removes an alias from the list
 * @information: parameter struct
 * @alias_string: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int remove_alias(information_t *information, char *alias_string)
{
	char *p, c;
	int ret;

	p = _strchr(alias_string, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(information->alias_list),
		get_node_index(information->alias_list, node_starts_with(information->alias_list, alias_string, -1)));
	*p = c;
	return (ret);
}

/**
 * add_alias - adds an alias to the list
 * @information: parameter struct
 * @alias_string: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int add_alias(information_t *information, char *alias_string)
{
	char *p;

	p = _strchr(alias_string, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (remove_alias(information, alias_string));

	remove_alias(information, alias_string);
	return (add_node_end(&(information->alias_list), alias_string, 0) == NULL);
}

/**
 * print_alias_string - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias_string(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * print_alias - mimics the alias builtin (man alias)
 * @information: Structure containing potential arguments. Used to maintain
 *                constant function prototype.
 * Return: Always 0
 */
int print_alias(information_t *information)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (information->argument_count == 1)
	{
		node = information->alias_list;
		while (node)
		{
			print_alias_string(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; information->arguments[i]; i++)
	{
		p = _strchr(information->arguments[i], '=');
		if (p)
			add_alias(information, information->arguments[i]);
		else
			print_alias_string(node_starts_with(information->alias_list, information->arguments[i], '='));
	}

	return (0);
}
