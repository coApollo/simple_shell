#include "main.h"

/**
 * _printerror - Display custom error message to stderr
 *
 * @exec_commands: The number of commands executed from the shell
 * @arg_count: The number of arguments to expect
 *Return: Nothing
 */
void _printerror(int exec_commands, int arg_count, ...)
{
	int size = 0, arg_found = 0;
	va_list arg;
	char *message;

	va_start(arg, arg_count);
	while (arg_found < arg_count)
	{
		message = va_arg(arg, char *);
		size = _strlen(message) - 1;
		write(STDERR_FILENO, message, size);
		if (arg_found == 1)
		{
			print_number(exec_commands);
		}
		arg_found++;
	}
}

/**
 * print_number - Display the given integer.
 *
 *@number: The number to be printed
 *Return: Nothing
 **/
void print_number(int number)
{
	char buffer[sizeof(int) + 1];
	int i = 0;
	int j = 0;

	if (number < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		number = -number;
	}

	if (number == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (number > 0)
		{
			buffer[i++] = '0' + (number % 10);
			number /= 10;
		}
	}

	for (j = i - 1; j >= 0; j--)
		write(STDOUT_FILENO, &buffer[j], 1);

}


/**
 *_print_str - writes a string to stdout
 *
 *@str: string to be written
 *Return: Nothing
 */
void _print_str(char *str)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, str, _strlen(str));
	}
	else
	{
		write(STDOUT_FILENO, str, _strlen(str));
	}
}


/**
 *_putchar - writes a single character to spacified file
 *	descriptor(fd)
 *
 *@ch: The character to be written
 *@file_descriptor: The file descriptor to be used when writing bytes
 *Return: On success 1.
 *	:On error, -1 is returned, and errno is set appropriately.
 */
void _putchar(char ch, int file_descriptor)
{
	write(file_descriptor, &ch, 1);
}


/**
 * _printenv - Prints the environment variables
 *
 *Return: Nothing
 */
void _printenv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{

		_print_str(environ[i]);
		_putchar('\n', 1);

		i++;
	}

}
