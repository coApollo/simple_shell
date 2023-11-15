#include "main.h"

/**
 * _free_ - Frees memory allocated to commands to be executed by the shell
 *
 * @args: The given commands to be executed
 *Return: Nothing
*/
void _free_(char **args)
{
	if (args != NULL)
	{
		free(args);
		args = NULL;
	}
}


/**
 *free_list - frees a linked list
 *
 *@head: the head node of the list
 *Return: Nothing
 */
void free_list(node_t *head)
{
	node_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * _free_str - Frees memory allocated to any string used in the shell that
 * needs to be freed
 *
 * @str: A string to be freed
 *Return: Nothing
 */
void _free_str(char *str)
{
	free(str);
	str = NULL;
}
