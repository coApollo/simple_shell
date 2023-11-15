#include "main.h"

/**
 * _prompt - Displays a prompt to the user and accept(reads)
 * the command to be executed
 *
 * @buf: The memory address to store command string
 * @bytes_read: number of bytes written to @buffer
 *
 *Return: EXIT_SUCCESS if @buffer has a value
 *	: EOF if end of file is reached
 */
int _prompt(char **buf, size_t *bytes_read)
{
	int actual_bytes_read = 0;
	int mode = NON_INTERACTIVE_MODE;

	mode = _check_mode();
	if (mode == INTERACTIVE_MODE)
	{
		write(1, "$ ", 2);
	}
	actual_bytes_read = getline(buf, bytes_read, stdin);
	if (actual_bytes_read != EOF)
	{
		if ((*buf)[actual_bytes_read - 1] == '\n')
		{
		    (*buf)[actual_bytes_read - 1] = '\0';
		}
		return (EXIT_SUCCESS);
	}
	if (mode == INTERACTIVE_MODE)
	{
		write(1, "\n", 1);
	}
	return (EOF);
}
