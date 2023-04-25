#include "shell.h"

/**
 * buffer_input - buffers chained commands
 * @info: parameter struct
 * @buffer: address of buffer
 * @len: address of length variable
 *
 * Return: bytes read
 */
ssize_t buffer_input(info_t *info, char **buffer, size_t *len)
{
	ssize_t bytes_read = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->command_buffer);*/
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, block_ctrlc);
#if USE_GETLINE
		bytes_read = getline(buffer, &len_p, stdin);
#else
		bytes_read = _getline(info, buffer, &len_p);
#endif
		if (bytes_read > 0)
		{
			if ((*buffer)[bytes_read - 1] == '\n')
			{
				(*buffer)[bytes_read - 1] = '\0'; /* remove trailing newline */
				bytes_read--;
			}
			info->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(info, *buffer, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = bytes_read;
				info->command_buffer = buffer;
			}
		}
	}
	return (bytes_read);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t bytes_read = 0;
	char **arg = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	bytes_read = buffer_input(info, &buf, &len);
	if (bytes_read == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buf + i; /* get pointer for return */

		check_chain(info, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*arg = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*arg = buf; /* else not a chain, pass back buffer from _getline() */
	return (bytes_read); /* return length of buffer from _getline() */
}

/**
 * read_buffer - reads a buffer
 * @info: parameter struct
 * @buffer: buffer
 * @i: size
 *
 * Return: bytes read
 */
ssize_t read_buffer(info_t *info, char *buffer, size_t *i)
{
	ssize_t bytes_read = 0;

	if (*i)
		return (0);
	bytes_read = read(info->readfd, buffer, READ_BUF_SIZE);
	if (bytes_read >= 0)
		*i = bytes_read;
	return (bytes_read);
}

/**
 * _getline - gets the next line of input from STDIN
 *
