#include "shell.h"

/**
 * get_hist_file - retrieves the history file path
 * @inf: a parameter struct
 *
 * Return: an allocated string containing the history file path
 */
char *get_hist_file(inf_t *inf)
{
	char *buf, *dir;

	dir = _getenv(inf, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * wr_hist - creates a file, or appends to an existing file
 * @inf: a parameter struct
 *
 * Return: 1 on success, -1 on failure
 */
int wr_hist(inf_t *inf)
{
	ssize_t fd;
	char *filename = get_hist_file(inf);
	list_t *node = NULL;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = inf->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * rd_hist - reads history from a file
 * @inf: a parameter struct
 *
 * Return: the number of history lines read on success, 0 otherwise
 */
int rd_hist(inf_t *inf)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_hist_file(inf);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = '\0';
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			bld_hist_lst(inf, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		bld_hist_lst(inf, buf + last, linecount++);
	free(buf);
	inf->histcount = linecount;
	while (inf->histcount-- >= HIST_MAX)
		del_node_at_index(&(inf->history), 0);
	renumber_history(inf);
	return (inf->histcount);
}

/**
 * bld_hist_lst - adds an entry to the history linked list
 * @inf: a parameter struct
 * @buf: a buffer
 * @linecount: the history line count
 *
 * Return: Always 0
 */
int bld_hist_lst(inf_t *inf, char *buf, int linecount)
{
	list_t *node = NULL;

	if (inf->history)
		node = inf->history;
	add_node_end(&node, buf, linecount);

	if (!inf
