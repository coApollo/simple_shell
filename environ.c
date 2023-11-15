#include "main.h"

/**
 *get_envs - Extracts and duplicates environment variables into a new array.
 *
 *@env: original array of environment variable
 *Return:  A new array containing duplicated environment variables,
 *      or NULL on failure to allocate memory.
 */
char **get_envs(char **env)
{
	char **clone = NULL;
	int count = 0, i = 0, j = 0;
	char *name = NULL, *val = NULL;

	while (env[count] != NULL)
	{
		count++;
	}

	clone = (char **)malloc(sizeof(char *) * (count + 1));
	if (clone == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < count; i++)
	{
		clone[i] = _strdup(env[i]);

		if (clone[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(clone[j]);
			}
			free(clone);
			return (NULL);
		}

		name = strtok(clone[i], "=");
		val = strtok(NULL, "\n");

		if (name && val)
			addnodeend(&head, name, val);

	}

	clone[count] = NULL;

	return (clone);
}

/**
 * getenv_path - Retrieves the value of the PATH environment variable.
 *
 *Return: A pointer to the value of the PATH environment variable,
 *         or NULL if the variable is not found.
 */
char *getenv_path(void)
{
	node_t *current = head;

	while (current)
	{
		if (_isenvvarpath(current->name) == IS_PATH)
			return (current->value);

		current = current->next;
	}

	return (NULL);
}

/**
 *check_envs - Checks if the given command is "env" and executes accordingly.
 *
 *@str: The string to check
 *Return: EXIT_SUCCESS if the command is "env",
 *      : EXIT_FAILURE otherwise
 */
int check_envs(char *str)
{
	char *env = "env";

	if (str == NULL)
		return (EXIT_FAILURE);

	if (_strcmp(str, env) != 0)
		return (EXIT_FAILURE);

	_printenv();
	_signal_ = EXIT_SUCCESS;
	return (EXIT_SUCCESS);
}

/**
 * set_envs - Sets or adds an environment variable with the specified
 *      name and value
 *
 *@name: The name of the environment variable to set or add
 *@value: The value to assign to the environment variable
 *@num: Flag indicating whether to overwrite an existing
 *       variable (OVERWRITE) or not
 *Return: EXIT_SUCCESS on successful operation
 *      : ERROR_OCCURRED on error
 */
int set_envs(const char *name, const char *value, int num)
{
	node_t *node = NULL;

	if (name == NULL || value == NULL || strchr(name, '=') != NULL)
	{
		errno = EINVAL;
		return (ERROR_OCCURRED);
	}

	node = find_node(head, (char *)name);

	if (node == NULL)
		addnodeend(&head, (char *)name, (char *)value);

	else if (num == 1)
		node->value = (char *)value;

	return (EXIT_SUCCESS);
}

