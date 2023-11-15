#include "main.h"

/**
 * _strcat - concatenates two strings
 *
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */
char *_strcat(char *dest, char *src)
{

	int len = 0;
	int i = 0;

	while (dest[len] != '\0')
		len++;

	for (i = 0; src[i] != '\0'; i++, len++)
		dest[len] = src[i];

	dest[len] = '\0';
	return (dest);
}
/**
 *_strncmp - compares a number of chars in a string
 *
 *@s1: first string
 *@s2: second string
 *@num: number of chars to compare
 *Return: 0
 */
int _strncmp(const char *s1, const char *s2, size_t num)
{

	while (num > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		num--;
	}

	return (0);

}
