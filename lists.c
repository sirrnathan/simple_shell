#include "shell.h"

/**
 * add_node_start - adds a node to the start of the list
 * @h: address of pointer to head node
 * @str: str field of node
 * @idx: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_start(list_t **h, const char *str, int idx)
{
	list_t *new_head;

	if (!h)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->idx = idx;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *h;
	*h = new_head;
	return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @h: address of pointer to head node
 * @str: str field of node
 * @idx: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **h, const char *str, int idx)
{
	list_t *new_node, *node;

	if (!h)
		return (NULL);

	node = *h;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->idx = idx;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*h = new_node;
	return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @h: address of pointer to first node
 * @idx: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **h, unsigned int idx)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);

	if (!idx)
	{
		node = *h;
		*h = (*h)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *h;
	while (node)
	{
		if (i == idx)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @h_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **h_ptr)
{
	list_t *node
