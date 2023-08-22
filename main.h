#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct print_func_type - Structure that defines the printing functions
 *
 * @type: the format specifier character
 * @func: the corresponsing function to specifier
 */
typedef struct print_func_type
{
	char type;
	int (*func)(va_list);
} print_func_type;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_mod(va_list args);
int print_int(va_list args);
int print_binary(va_list args);

#endif /* MAIN_H */
