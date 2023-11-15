#include "main.h"

/**
 * _exit_ - frees momory while exiting
 *
 * @path: A pointer to the environment PATH variables
 * @env: A pointer to a copy of the users env's
 * @buf: The command entered by user
 * Return: the exit code for last successfull command
 */
int _exit_(char **path, char **env, char *buf)
{
	int i = 0;

	if (path != NULL)
	{
		_free_str(path[0]);
	}
	while (env[i] != NULL)
	{
		_free_str(env[i++]);
	}
	_free_(env);
	_free_str(buf);
	_free_(path);
	free_list(head);
	return (_signal_);
}

/**
 * handle_sigint - handles Ctrl + C signal
 *
 *@signum: The signal number obtained
 *Return: Nothing
 */
void handle_sigint(int signum __attribute__((unused)))
{

	_signal_ = CTRL_C_SIGNAL_CODE;
	write(1, "\n$ ", 3);
}


/**
 * _atoi - Converts a string to an integer.
 *
 * @str: The string to be converted to an integer
 * Return: The converted integer
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		++i;
	}
	return (sign * result);
}
