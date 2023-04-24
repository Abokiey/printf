#include <stdarg.h>
#include "main.h"
#include <limits.h>
#include <stdlib.h>

/**
 * print_unsigned - manage unsigned int
 * @args: argument list
 * Return: value number of printed chars
 */

int print_unsigned(va_list args)
{
	unsigned int argument = va_arg(args, unsigned int);

	return (print_unsigned_number(argument));
}
/**
 * print_ptr - print adress
 * @args: argument void
 * Return: number of printed char
 */
int print_ptr(va_list args)
{
	char *str;
	int sum = 0;
	unsigned long p = (unsigned long) va_arg(args, void*);

	if (!p)
	{
		sum += _puts("(nil)", 0);
		return (sum);
	}

	str = convert_base_pointer(p);
	if (!str)
		return (0);
	sum += _puts("0x", 0);
	sum += _puts(str, 0);
	free(str);
	return (sum);
}
