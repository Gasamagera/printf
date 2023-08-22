#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Function that produces output according to a format
 *
 * @format: a character string
 * @...: variable arguments
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, counter = 0, j;

	print_func_type print_func[] = {
		{'c', print_char},
		{'s', print_str},
		{'i', print_int},
		{'d', print_int},
		{'%', print_mod},
		{'b', print_binary},
		{'\0', NULL}
	};

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j = 0;

			while (print_func[j].type != '\0')
			{
				if (print_func[j].type == format[i])
				{
					counter += print_func[j].func(args);
					break;
				}
				j++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			counter++;
		}
		i++;
	}
	va_end(args);

	return (counter);
}
