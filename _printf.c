#include "main.h"

/**
 * _printf - Printf function
 * @format: character string
 * Return:  number of Printed chars.
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
		if (*format == 'c')
		{
			putchar(va_arg(args, int)), count++;
		}
		else if (*format == 's')
		{
			for (char *s = va_arg(args, char *); *s; s++, count++)
			putchar(*s);
		}
		else if (*format == '%')
		{
			putchar('%'), count++;
		}
		else
		{
			putchar('%'), putchar(*format), count += 2;
		}
		}
		else
		{
			putchar(*format), count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

