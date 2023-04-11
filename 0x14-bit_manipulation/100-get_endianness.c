#include "main.h"

/**
 * get_endianness - checks if machine is little or big endian
 * Return: 0 (big), 1 (little)
 */
int get_endianness(void)
{
	unsigned int k = 1;
	char *c = (char *) &k;

	return (*c);
}
