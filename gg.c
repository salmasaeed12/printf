#include <stdio.h>

/**
 * print_number - print number
 *
 * @n: the number
 */
void print_number(int n)
{
	unsigned int nl;

	nl = n;
	if (n < 0)
	{
		putchar('-');
		nl = -n;
	}
	if (nl / 10 != 0)
	{
		print_number(nl / 10);
	}
	putchar((nl % 10) + '0');
}
int main(void)
{
	/*print_number(98);
    putchar('\n');
    print_number(402000);
    putchar('\n');
    print_number(1024);
    putchar('\n');
    print_number(0);
    putchar('\n');*/
	print_number(125006556);
	putchar('\n');
	return (0);
}
