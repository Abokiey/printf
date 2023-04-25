#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * print_unsigned_number - prints unsigned number
 * @n: the unsigned int to be printed
 * Return: printed chars
 */

int print_unsigned_number(unsigned int n)
{
	int count = 0;
	unsigned int i = n;

	if (i <= 9)
	{
	_putchar(i + '0');
	return (1);
	}
	if (i > 9)
	{
	count = print_unsigned_number(i / 10) + 1;
	_putchar(i % 10 + '0');
	return (count);
	}
	return (0);
}

/**
 * print_number - displays the number contained in an int
 * @n: int to be printed
 * Return: number of chars
 */
int print_number(int n)
{
	unsigned int i;
	int count = 0;

	i = n;
	if (n < 0)
	{
	_putchar('-');
	count++;
	i = -i;
	}
	if (i <= 9)
	{
	count += _putchar(i + '0');
	return (count);
	}
	if (i > 9)
	{
	count += print_number(i / 10) + 1;
	_putchar(i % 10 + '0');
	return (count);
	}
	return (0);
}
/**
 * _nbr_len - gives the length of a number
 * @prmNumber: number
 * Return: length of the number
 */

int _nbr_len(int prmNumber)
{
	int p = 0, n;

	if (prmNumber == 0)
		return (1);

	n = prmNumber;

	if (n < 0)
	{
	n *= -1;
	p++;
	}

	while (n)
	{
	n /= 10;
	p++;
	}

	return (p);
}

/**
 * _itoa - it converts an int into a string
 * @prmNumber: int to be converted
 * Return: converted string
 */

char *_itoa(int prmNumber)
{
	char *s;
	int p;
	long n;

	n = prmNumber;
	p = _nbr_len(n);
	s = malloc(sizeof(char) * p + 1);

	if (s == NULL)
	{
	return (NULL);
	}

	s[p] = '\0';

	if (n == 0)
	{
	s = "0";
	}
	else if (n < 0)
	{
	s[0] = '-';
	n *= -1;
	}

	while (n)
	{
	s[--p] = n % 10 + 48;
	n /= 10;
	}

	return (s);
}

