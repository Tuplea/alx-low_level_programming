#include "main.h"

/**
 * print_binary - prints the binary equivalent of a dec no
 * @n: no to print in binary
 */
void print_binary(unsigned long int n)
{
	int k, add = 0;
	unsigned long int new;

	for (k = 63; k >= 0; k--)
	{
		new = n >> k;

		if (new & 1)
		{
			_putchar('1');
			add++;
		}
		else if (add)
			_putchar('0');
	}
	if (!add)
		_putchar('0');
}
