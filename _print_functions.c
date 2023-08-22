#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_int - Function that prints an integer
 *
 * @args: List of arguments
 *
 * Return: Number of arguments
 */
int print_int(va_list args)
{
	int x = va_arg(args, int);
	int i = 1, counter = 0;
	unsigned int n;
	char c;

	if (x == 0)
	{
		write(1, "0", 1);
		counter++;
		return (counter);
	}

	if (x < 0)
	{
		counter += write(1, "-", 1);
		n = x * -1;
	}
	else
		n = x;

	while (n / i > 9)
		i *= 10;

	while (i != 0)
	{
		c = n / i + '0';
		counter += write(1, &c, 1);
		n = n % i;
		i /= 10;
	}

	return (counter);
}

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
	char mod = '%';

	(void)args;

	write(1, &mod, 1);
	return (1);
}

/**
 * print_binary - Function that converts its unsigned int argument to
 * binary and prints it
 *
 * @args: The unsigned int to be convert and printed
 *
 * Return: Number of printed characters
 */
int print_binary(va_list args)
{
	int i, counter = 0;
	unsigned int x = va_arg(args, unsigned int);
	char c;

	for (i = 31; i >= 0; i--)
	{
		if ((x >> i) & 1)
		{
			c = '1';
			write(1, &c, 1);
			counter++;
		}
		else if (counter > 0)
		{
			c = '0';
			write(1, &c, 1);
			counter++;
		}
	}

	return (counter);
}
