#include "main.h"

/**
 * _execute - Execute command with thew given args
 *
 * @args: Array of command arguments, including the command itself
 * @num: Command number (for error reporting)
 * @program: Name of the program
 * @env: Environment variables
 * Return: Exit status of the executed command
 */
int _execute(char **args, int num, char *program, char **env)
{
	char *path = NULL;
	int status = 0;
	pid_t pid;
	int info = VALID;

	path = args[0];
	info = _check_file(path);

	if (info == VALID)
	{
		pid = fork();
		if (pid == -1)
		{
			return (errno);
		}
		if (pid == 0)
		{
			_signal_ = EXIT_SUCCESS;
			if (execve(path, args, env) == ERROR_OCCURRED)
			{
				_signal_ = status;
				_exit(EXIT_FAILURE);
			}
		}
		wait(&status);
		if (WIFEXITED(status))
		{
			_signal_ = WEXITSTATUS(status);
			return (WEXITSTATUS(status));
		}
	}
	else if (info == INVALID || info == _REL_)
	{
		_printerror(num, 5, program, ": ", ": ",
		path, ": not found\n");
		_signal_ = INVALID;
		return (INVALID);
	}
	return (status);
}

