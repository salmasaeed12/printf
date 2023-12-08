#include "main.h"
/**
 * print_uintb -prints an unsigned integer
 *    to the buffer based on the specified format.
 *
 * @args: Variable argument list.
 * @buffer: Pointer to the buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 * @buffer_size: Pointer to the size of the buffer.
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
/**
 * p_generic_pointer - Handles the printing of a
 *    generic pointer in a formatted string.
 * @pb: Pointer to the current position in the buffer.
 * @ar: Pointer to the variable arguments list.
 * @size: Pointer to the size of the buffer.
 * @buf: Pointer to the buffer.
 * @len_buf: Length of the current buffer content.
 *
 * This function interprets the
 *  generic pointer provided as an array of bytes and
 * copies each byte to the buffer.
 *   It ensures proper buffer handling and resizing
 * to prevent buffer overflow.
 *
 * Return: Pointer to the updated buffer position.
 */
char *p_generic_pointer(char *pb, va_list *ar, int *size,
char **buf, int len_buf __attribute__((unused)))
{
void *ptr;
char *byte_ptr;
int i;
ptr = va_arg(*ar, void *);

if (ptr == NULL)
{
return (pb);
}
byte_ptr = (char *)ptr;
for (i = 0; i < _strlen(byte_ptr); ++i)
{
len_buf = *buf - pb;
if (len_buf == *size - 1)
pb = change_len(size, pb, buf, len_buf);
*pb = *(byte_ptr + i);
++pb;
}
return (pb);
}
