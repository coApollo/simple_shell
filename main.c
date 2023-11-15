#include "main.h"

int _signal_ = 0;
node_t *head = NULL;

/**
 * main - simple shell implementation
 *
 * Entry point for a simple shell. Initializes variables, sets signal
 * handlers, and enters a loop to prompt for commands. Handles command
 * execution, environment variables, and supports graceful shell exit
 * using "exit" or Ctrl+C. Loop continues until an exit condition.
 *
 * @argc: Number of command-line arguments (unused)
 * @argv: Array of command-line arguments
 * @env: Array of environment variables
 * Return: Exit status of the shell
 */
int main(int argc __attribute__((unused)), char *argv[], char *env[])
{
	char *buf = NULL;
	char **cmnds = NULL,  **envpath = NULL, **envclon = NULL;
	size_t bytes_read = 0;
	int exec_count = 0;
	int _quit = NULL_FOUND, _info = VALID;

	signal(SIGINT, handle_sigint);
	envclon = get_envs(env);
	set_envs(SHLVL_NAME, SHLVL_VAL, 0);
	envpath = _get_paths(head);
	while (true)
	{
		exec_count++;
		_quit = -2;
		if (_prompt(&buf, &bytes_read) == EOF)
			return (_exit_(envpath, envclon, buf));

		cmnds = _tokenization(buf, " \t\r\n");
		_is_exit(cmnds, buf, envpath, _signal_, envclon);
		if (check_envs(cmnds[0]) == EXIT_SUCCESS)
		{
			_free_(cmnds);
			continue;
		}
		_info = _check_file(cmnds[0]);
		_rel_path(&_info, envpath, cmnds, buf, &_quit);
		_quit = _execute(((_quit == CTRL_C_SIGNAL_CODE) ?
		&buf : cmnds), exec_count, argv[0], env);
		if (_quit == EXIT_SUCCESS && _info == _REL_)
		{
			_free_str(cmnds[0]);
		}
		_free_(cmnds);
	}
	return (_quit);
}
