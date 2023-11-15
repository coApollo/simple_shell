#include "main.h"

/**
 * addnodeend - Add a new environment variable to env list
 *
 * @head: The head node in the list
 * @name: The name for the env to be added as the tail
 * @value: The value for env to be added
 * Return: The address to the newly added node
*/
node_t *addnodeend(node_t **head, char *name, char *value)
{
	node_t *tail, *current;

	tail = malloc(sizeof(node_t));
	tail->name = name;
	tail->value = value;
	tail->next = NULL;

	if (*head == NULL)
	{
		*head = tail;
		return (tail);
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tail;
	return (tail);
}


/**
 * find_node - finds a node from the list of env's
 *
 * @head: The head node in the list of env's
 * @name: The name for the variable to be searched
 * Return:@name
 *
 */
node_t *find_node(node_t *head, char *name)
{
	node_t *current = head;

	while (current != NULL)
	{
		if (_strcmp(current->name, name) == 0)
			return (current);

		current = current->next;
	}

	return (NULL);
}

