#include "main.h"

/**
 * _rel_path - Checks for relative path
 *
 * @file: A value
 * @envpath:pointer to the PATH variables
 * @cmnds: A pointer to a string of commands
 * @buf: The input accepted from the user
 * @exit_: A pointer to the exit status of the shell
 *Return: Nothing
 */
void _rel_path(int *file, char **envpath, char **cmnds
		, char *buf, int *exit_)
{
	int i = 0;

	if (*file == _REL_)
	{
		while (envpath != NULL &&
		envpath[i] != NULL)
		{
			*exit_ = NULL_FOUND;
			cmnds[0] = _abs_path(envpath[i],
					strtok(buf, " \t\r\n"));
			if (_check_file(cmnds[0]) == VALID)
			{
				*exit_ = EXIT_SUCCESS;
				break;
			}
			*exit_ = CTRL_C_SIGNAL_CODE;
			i++;
			_free_str(cmnds[0]);
		}
	}
}

/**
 * _abs_path - gets absolute PATH to command
 *
 * @path: a path in the PATH environment variable
 * @command:command to be executed
 * Return: absolute path
*/
char *_abs_path(char *path, char *command)
{
	return (_make_path(3, path, "/", command));
}

/**
 * _make_path - Appends string @str to another to create path
 *
 * @argc: The number of strings to be appended to dest
 * Return: A pointer to a new memory address with the new path
*/
char *_make_path(int argc, ...)
{
	va_list args;
	int len = 0, i, j, index;
	char *new;
	const char *str;

	va_start(args, argc);

	for (i = 0; i < argc; i++)

		len += _strlen(va_arg(args, char *));

	va_end(args);

	va_start(args, argc);
	new = malloc(len + 1);
	index = 0;

	for (i = 0; i < argc; i++)
	{
		str = va_arg(args, const char *);
		for (j = 0; str[j] != '\0'; j++)
			new[index++] = str[j];

	}

	va_end(args);
	new[index] = '\0';

	return (new);
}


/**
 * _check_path - Check whether path is an absolute or relative
 *
 *@path: The command to be executed. Could be the
 *path to the command or merely the command name
 *Return: VALID_COMMAND if it is a valid absolute
 *	:IS_REL_PATH if it is absolute
 */
int _check_path(char *path)
{
	return (_check_file(path));
}

