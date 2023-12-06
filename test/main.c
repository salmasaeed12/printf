#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len2 = printf("good%d%s%dgood", 123456789, "Tariq", 123);
	printf("\n\n");
	len = _printf("good%d%s%dgood", 123456789, "Tariq", 123);
	fflush(stdout);
	if (len != len2)
	{
		printf("\n%d\t%d", len2, len);
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
