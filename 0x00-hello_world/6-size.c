#include <stdio.h>
/**
 * main - program prints the size of computer types compiled
 * Return: 0 (Success)
 */
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float f;

printf("Size of a char: %lu byte($)\n", (unsigned long)sizeof(a));
printf("Size of an int: %lu byte($)\n", (unsigned long)sizeof(b));
printf("Size of a long int: %lu byte($)\n", (unsigned long)sizeof(c));
printf("Size of a long long int: %lu byte($)\n", (unsigned long)sizeof(d));
printf("Size of a float: %lu byte($)\n", (unsigned long)sizeof(f));
return (0);
}
