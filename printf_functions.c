#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_num - print number
 * @args: argument list
 * Return: number of printed char
 */

int print_num(va_list args)
{
	return (print_number(va_arg(args, int)));
}

/**
 * print_binary - print number binary base
 * @args: argument list
 * Return: number of printed char
 */

int print_binary(va_list args)
{
	char *str;
	int sum = 0;
	unsigned int argument = va_arg(args, unsigned int);

	if (!argument)
	{
		sum += _puts("0", 0);
		return (sum);
	}
	str = convert_base(argument, 2, 0);
	if (!str)
		return (0);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

/**
 * print_octal - print number octal base
 * @args: argument list
 * Return: number of printed char
 */

int print_octal(va_list args)
{
	char *str;
	int sum;

	str = convert_base(va_arg(args, unsigned int), 8, 0);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

/**
 * print_hexa_lower - print hexa lower
 * @args: argument list
 * Return: number of printed char
 */

int print_hexa_lower(va_list args)
{
	char *str;
	int sum;

	str = convert_base(va_arg(args, unsigned int), 16, 0);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

/**
 * print_hexa_upper - print hexa upper
 * @args: argument list
 * Return: number of printed char
 */

int print_hexa_upper(va_list args)
{
	char *str;
	int sum;

	str = convert_base(va_arg(args, unsigned int), 16, 1);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}
