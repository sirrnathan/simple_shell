#include "shell.h"

/**
 * print_current_env - prints the current environment
 * @information: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int print_current_env(information_t *information)
{
	print_list_str(information->env);
	return (0);
}

/**
 * get_env_value - gets the value of an environ variable
 * @information: Structure containing potential arguments. Used to maintain
 * @var_name: env var name
 *
 * Return: the value
 */
char *get_env_value(information_t *information, const char *var_name)
{
	list_t *node = information->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, var_name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * set_env_var - Initialize a new environment variable,
 *             or modify an existing one
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int set_env_var(information_t *information)
{
	if (information->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(information, information->argv[1], information->argv[2]))
		return (0);
	return (1);
}

/**
 * unset_env_var - Remove an environment variable
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int unset_env_var(information_t *information)
{
	int i;

	if (information->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= information->argc; i++)
		_unsetenv(information, information->argv[i]);

	return (0);
}

/**
 * populate_env_linked_list - populates env linked list
 * @information: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_linked_list(information_t *information)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	information->env = node;
	return (0);
}
