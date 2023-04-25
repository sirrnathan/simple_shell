#include "shell.h"

/**
 * count_list - determines length of linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t count_list(const list_t *head)
{
	size_t count = 0;

	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

/**
 * list_to_arr - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_arr(list_t *head)
{
	list_t *node = head;
	size_t i = count_list(head), j;
	char **str_arr;
	char *str;

	if (!head || !i)
		return (NULL);
	str_arr = malloc(sizeof(char *) * (i + 1));
	if (!str_arr)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(str_arr[j]);
			free(str_arr);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		str_arr[i] = str;
	}
	str_arr[i] = NULL;
	return (str_arr);
}


/**
 * print_node_list - prints all elements of a list_t linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t print_node_list(const list_t *head)
{
	size_t count = 0;

	while (head)
	{
		_puts(convert_number(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		count++;
	}
	return (count);
}

/**
 * get_match_node - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *get_match_node(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head)
	{
		if (head == node)
			return (index);
		head = head->next;
		index++;
	}
	return (-1);
}
