#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: number of printed char
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes all chars from string to stdout
 * @str: string to be printed
 * @ascii: enable ascii restriction
 * Return: number of printed chars
 */

int _puts(char *str, int ascii)
{
	char *s;
	int j = 0, sum = 0;

	while (str[j])
	{
		if (((str[j] >= 0 && str[j] < 32) || str[j] >= 127) && ascii)
		{
			s = convert_base(str[j], 16, 1);
			sum += write(1, "\\x", 2);
			if (str[j] >= 0 && str[j] < 16)
			sum += _putchar('0');
			sum += _puts(s, 0);
			free(s);
			j++;
		}
		else
		{
		sum += _putchar(str[j]);
		j++;
		}
	}
	return (sum);
}

/**
 * _strlen_recursion - returns the length of a string
 * @s: is a char pointer
 * Return: the length of a string
 */
int _strlen_recursion(char *s)
{
	if (*s != '\0')
	{
		return (_strlen_recursion(s + 1) + 1);
	}
	else
	{
		return (0);
	}
}

/**
 * _strdup - a pointer to a newly allocated space in memory,
 * @str: char pointer to be copied
 * Return: a new char pointer
 */
char *_strdup(char *str)
{
	char *s;
	int p;

	if (str == NULL)
	{
		return (NULL);
	}

	s = malloc(sizeof(char) * (_strlen_recursion(str) + 1));

	if (s == NULL)
	{
		return (NULL);
	}

	for (p = 0; p < _strlen_recursion(str) + 1; p++)
	{
		s[p] = str[p];
	}

	return (s);
}
