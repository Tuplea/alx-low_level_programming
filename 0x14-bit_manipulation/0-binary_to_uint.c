#include "main.h"

/**
 * binary_to_uint - change a binary to unsigned int
 * @b: string contains binary number
 *
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int k;
	unsigned int dis_value = 0;

	if (!b)
		return (0);

	for (k = 0; b[k]; k++)
	{
		if (b[k] < '0' || b[k] > '1')
			return (0);
		dis_value = 2 * dis_value + (b[k] - '0');
	}

	return (dis_value);
}
