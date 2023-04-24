#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 * get_op - select function for conversion char
 * @c: char to check
 * Return: pointer to function
 */

int (*get_op(const char c))(va_list)
{
	int i = 0;

	PrintfFlags pf[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"i", print_num},
		{"d", print_num},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{"u", print_unsigned},
		{"S", print_str_unprintable},
		{"r", print_str_reverse},
		{"p", print_ptr},
		{"R", print_rot13},
		{"%", print_percent}
	};
	while (i < 14)
	{
		if (c == pf[i].c[0])
		{
			return (pf[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * _printf - Reproduce behavior of printf function
 * @format: format string
 * Return: value of printed chars
 */

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0, i = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = get_op(format[i + 1]);
			if (func == NULL)
			{
				_putchar(format[i]);
				printed_chars++;
				i++;
			}
			else
			{
				printed_chars += func(args);
				i += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
			i++;
		}
	}
	va_end(args);
	return (printed_chars);
}
