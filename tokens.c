#include "main.h"

/**
 * _tokenization - breakes a string into tokens and stores the into an
 *array.
 *
 * @str: string to be tokenized
 * @del :delimeter
 * Return: An array of tokens
 */
char **_tokenization(char *str, char *del)
{
	char **token_arr = NULL;
	int count = 0;
	int found = 0;
	char *token = NULL;
	int len = 0;

	len = _strlen(str);
	token = malloc(sizeof(char) * (len + 1));
	_strcpy(token, str);
	count = _token_count(token, del);
	_free_str(token);
	token_arr = malloc(sizeof(char *) * (count + 1));
	str = strtok(str, del);
	while (str != NULL)
	{
		token_arr[found++] = str;
		str = strtok(NULL, del);
	}
	token_arr[found] = str;
	return (token_arr);
}


/**
 * _get_paths - gets the values for the PATH environment variable
 *
 * @head: head node in the list of environment variables
 * Return:pointer to a pointer of the PATH values
*/
char **_get_paths(node_t *head)
{
	char **path = NULL;
	char *name = NULL;
	char *val = NULL;
	int len = 0;
	node_t *curr = NULL;

	curr = head;
	while (curr != NULL)
	{
		name = curr->name;
		if (_isenvvarpath(name) == IS_PATH)
		{
			len = _strlen(curr->value);
			val = malloc(sizeof(char) * len);
			_strcpy(val, curr->value);
			break;
		}
		curr = curr->next;
	}
	if (val != NULL)
	{
		path = _tokenization(val, ":");
	}
	return (path);
}

/**
 *_token_count - counts number of tokens ...
 *
 *@str:string to token count
 *@del: separator || delimeter
 *Return: number of tokens counted
 */
int _token_count(char *str, char *del)
{
	int count = 0;
	char *token = NULL;
	char *tmp = NULL;

	tmp = _strdup(str);
	token = strtok(tmp, del);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, del);
	}
	free(tmp);
	return (count);
}

