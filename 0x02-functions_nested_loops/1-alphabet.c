#include "main.h"

/**
 * main - program print lowercase alphabet
 * Return: void
 */
void print_alphabet(void)
{
	char c;
	for (c = 'a'; c <= 'z'; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}
