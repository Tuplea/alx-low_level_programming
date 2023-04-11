/**
 * flip_bits - counts bits to change
 * from one number to another
 * @n: 1st number
 * @m: 2nd number
 *
 * Return: bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int k, add = 0;
	unsigned long int new;
	unsigned long int exclude = n ^ m;

	for (k = 63; k >= 0; k--)
	{
		new = exclude >> i;
		if (new & 1)
			add++;
	}

	return (add);
}
