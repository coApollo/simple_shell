#include "main.h"

/**
 *_is_rel - checks if path is absolute || relative
 *
 *@path: The path to check
 *Return: _ABS_(1) if @path is an absolute file path
 *	: _REL_(2) otherwise
 */
int _is_rel(char *path)
{
	if (path[0] == '/')
		return (_ABS_);

	return (_REL_);
}

/**
 * _isenvvarpath - checks is @env_variable is the PATH
 *	environment variable
 *
 * @env_var: The given environment variable
 * Return: IS_PATH when @env_variable is a pointer to the PATH
 * environment variable
 *	:otherwise NOT_PATH
 */
int _isenvvarpath(char *env_var)
{
	if (_strcmp(env_var, "PATH") != 0)
		return (NOT_PATH);

	return (IS_PATH);

}

/**
 *_is_exec - checks if @path represents an executable
 *
 *@path: path to the executable.
 *Return: IS_EXEC if @path is a path to an executable
 *	:otherwise IS_REL_PATH
 */
int _is_exec(char *path)
{

	if (_strncmp(path, "./", 2) == 0)
		return (IS_EXEC);

	return (_REL_);
}

/**
 * _is_exit - checks if comand is the exit and handles accordingly
 *
 * @args: array of strings(commands)
 * @buf: command buffer
 * @envpath: Array of envronment path
 * @_signal_: The exit status to be used in exiting
 * @env_clone: The address to the cloned environment variable
 * Return: Nothing
*/
void _is_exit(char **args, char *buf, char **envpath,
int _signal_, char **env_clone)
{
	node_t *head = NULL;
	int i;

	if (args[0] == NULL)
		return;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			_signal_ = _atoi(args[1]);
		}

		_free_str(buf);
		_free_(args);

		if (envpath != NULL)
		{
			_free_str(envpath[0]);
			_free_(envpath);
		}

		for (i = 0; env_clone[i] != NULL; i++)
			_free_str(env_clone[i]);

		_free_(env_clone);

		free_list(head);

		print_number(_signal_);
		_putchar('\n', 1);

		exit(_signal_);
	}
}

