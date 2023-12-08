#include "main.h"
/**
 * print_uintb -prints an unsigned integer
 *    to the buffer based on the specified format.
 *
 * @args: Variable argument list.
 * @buffer: Pointer to the buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 * @buffer_size: Pointer to the size of the buffer.
 * @spe_char: Format specifier character ('o', 'u', 'x', etc.).
 * Return: None.
 */
void print_uintb(va_list args, char *buffer, int *buffer_index,
int *buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);

	write_integerX(&buffer, buffer_index, num, 2, buffer_size);
}
/**
 * pp_b - Store a string
 *
 * @pb: Pointer to buffer
 * @ar: The list of arguments
 * @size: pointer to size
 * @buf: Pointer to buffer
 * @len_buf: Check if buffer is full or not
 * Return: the next address
 */
char *pp_b(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buffer_index;

	buffer_index = pb - *buf;/*e*/
	(void)(len_buf);
	print_uintb(*ar/*e*/, *buf/*e*/, &buffer_index/*e*/, size);
	return ((buffer_index - 1) + *buf);
}
