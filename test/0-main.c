#include "../main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always (0)
 */
int main(void)
{
	int x = 5;
	double y = 3.14;
	char c = 'a';
	char *str = "Hello, World !";
	char mod = '%';

	my_printf("The value of x is %d, y is %f, c is %c, str is %s, mod is %%", x, y, c, str, mod);
	return (0);
}
