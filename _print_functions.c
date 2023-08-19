#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Function that prints a character
 *
 * @args: List of arguments
 *
 * Return: Number of printed characters
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_str - Function that prints a string
 *
 * @args: List of arguments
 *
 * Return: Number of printed characters
 */
int print_str(va_list args)
{
	int i, counter = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		write(1, &str[i], 1);
		counter += 1;
	}

	return (counter);
}

/**
 * print_mod - Function that prints '%'
 *
 * @args: List of arguments
 *
 * Return: Number of printed characters
 */
int print_mod(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
