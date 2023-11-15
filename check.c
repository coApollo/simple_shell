#include "main.h"

/**
 * _check_file - Check for the exisitence of a specified file
 *	in $PATH
 *
 *@path: The path to the execututable
 *Return:VALID if file exists and is executable/valid
 *	:NULL_FOUND if @path is NULL
 *otherwise INVALID
 */
int _check_file(char *path)
{
	int val;

	if (path == NULL)
	{
		return (NULL_FOUND);
	}
	val = _is_exec(path);
	if (val == 1)
	{
		if (access(path, F_OK) == VALID)
		{
			return (VALID);
		}
		return (INVALID);
	}
	val = _is_rel(path);
	if (val == 2)
	{
		return (_REL_);
	}
	if (access(path, F_OK) == VALID)
	{
		return (VALID);
	}
	return (INVALID);
}

/**
 * _check_mode - checks the operating mode of the shell
 *
 *Return:INTERACTIVE_MODE if the user is in the interactive
 *	mode otherwise NON_INTERACTIVE_MODE
 */
int _check_mode(void)
{
	if (isatty(STDIN_FILENO) != 1)
		return (NON_INTERACTIVE_MODE);

	return (INTERACTIVE_MODE);
}
