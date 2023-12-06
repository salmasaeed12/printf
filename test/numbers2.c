#include "main.h"
/**
 * pp_int - Store a string
 *
 * @pb: Pointer to buffer
 * @ar: The list of arguments
 * @size: pointer to size
 * @buf: Pointer to buffer
 * @len_buf: Check if buffer is full or not
 * Return: the next address
 */
char *pp_int(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buffer_index;

	buffer_index = pb - *buf;/*e*/
	(void)(len_buf);
	print_int(*ar/*e*/, *buf/*e*/, &buffer_index/*e*/, size);
	return ((buffer_index - 1) + *buf);
}
