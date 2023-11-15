#include "main.h"

/**
 * _strcmp - compares two strings.
 *
 *@s1:first string
 *@s2:second string
 *Return:negative number if s1 < s2,
 *	:positive number if s1 > s2 ||
 *0 if s1 is equal to s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);

	else
		return (*s1 - *s2);
}

/**
 * _strcpy - copies a string(src) to another
 *
 * @dest: destination string
 * @src: source string
 * Return: Pointer to destination string
 */
char *_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

/**
 * _strdup - Creates a duplicate for a string
 *
 * @str: The string to duplicate
 * Return:memory address to the newly allocated string.
*/
char *_strdup(char *str)
{
	char *dup = NULL;
	int len = 0;

	len = _strlen(str);
	dup = malloc(sizeof(char) * len);
	_strcpy(dup, str);

	return (dup);
}

/**
 * _strlen - find length of a string
 *
 * @str: The string to find len
 * Return: size string string
 **/
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i + 1);
}


/**
 * _strstr - searches for the first occurence of a substring
 *		in a string
 *
 *@haystack: The string to be searched
 *@needle: The string to search
 *Return: A pointer to the memory address
 *	that begins the located substring or NULL.
 */
const char *_strstr(const char *haystack, const char *needle)
{
	int i = 0;
	size_t s = strlen(needle);

	while (haystack[i] != '\0')
	{
		if (_strncmp(&haystack[i], needle, s) == 0)
			return (&haystack[i]);

		i++;
	}

	return (NULL);
}

