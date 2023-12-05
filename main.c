#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("%d", -1024);
	len2 = printf("%d", -1024);
	if (len != len2)
		printf("error");
	return (0);
}
