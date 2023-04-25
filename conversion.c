#include <stdlib.h>
#include "main.h"
/**
 * convert_alpha_numeric - convert digits to char
 * @num: a digitdigit number
 * @upper: if isupper
 * Return: converted value
 */

int convert_alpha_numeric(int num, int upper)
{
	if (num >= 10)
		return (num - 10 + ((upper) ? 'A' : 'a'));
	else
		return (num + '0');
}

/**
 * convert_base - convert unsigned from base 10 to base
 * @num: decimal number
 * @base: base to convert from
 * @upper: if isupper
 * Return: converted number to string
 */

char *convert_base(unsigned long num, unsigned int base, int upper)
{
	int i = 0;
	char *str;
	unsigned long nbr = num;

	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (0);
	str[i + 1] = '\0';

	while (i >= 0)
	{
		nbr = num % base;
		str[i] = convert_alpha_numeric(nbr, upper);
		num /= base;
		i--;
	}
	return (str);
}

/**
 * convert_base_pointer - convert pointer void to unsigned long
 * @p: pointer
 * Return: converted string
 */

char *convert_base_pointer(unsigned long p)
{
	unsigned long adress;
	char *str;

	adress = p;
	if (adress == 0)
		return ("0");
	str = convert_base(adress, 16, 0);
	return (str);
}
/**
 * convert_rot13 - encode using rot13
 * @str: string to encode
 * Return: encoded string
 */

char *convert_rot13(char *str)
{
	int i = 0;
	char *s;
	int size = _strlen_recursion(str);

	s = malloc(sizeof(char) * size + 1);
	if (!s)
		return (0);

	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
			s[i] = str[i] + 13;
		else if ((str[i] >= 'n' && str[i] <= 'z')
				|| (str[i] >= 'N' && str[i] <= 'Z'))
			s[i] = str[i] - 13;
		else
			s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
