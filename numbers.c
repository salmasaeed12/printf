#include "main.h"
/**
 * print_uint -prints an unsigned integer
 *    to the buffer based on the specified format.
 *
 * @args: Variable argument list.
 * @buffer: Pointer to the buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 * @buffer_size: Pointer to the size of the buffer.
 * @spe_char: Format specifier character ('o', 'u', 'x', etc.).
 * Return: None.
 */
void print_uinto(va_list args, char *buffer, int *buffer_index,
int *buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);

	write_integer(&buffer, buffer_index, num, 8, buffer_size);
}
/**
 * print_uint -prints an unsigned integer
 *    to the buffer based on the specified format.
 *
 * @args: Variable argument list.
 * @buffer: Pointer to the buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 * @buffer_size: Pointer to the size of the buffer.
 * @spe_char: Format specifier character ('o', 'u', 'x', etc.).
 * Return: None.
 */
void print_uintu(va_list args, char *buffer, int *buffer_index,
int *buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);

	write_integer(&buffer, buffer_index, num, 10, buffer_size);
}
/**
 * print_uint -prints an unsigned integer
 *    to the buffer based on the specified format.
 *
 * @args: Variable argument list.
 * @buffer: Pointer to the buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 * @buffer_size: Pointer to the size of the buffer.
 * @spe_char: Format specifier character ('o', 'u', 'x', etc.).
 * Return: None.
 */
void print_uintx(va_list args, char *buffer, int *buffer_index,
int *buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);

	write_integer(&buffer, buffer_index, num, 16, buffer_size);
}
/**
 * print_uintX -prints an unsigned integer
 *    to the buffer based on the specified format.
 *
 * @args: Variable argument list.
 * @buffer: Pointer to the buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 * @buffer_size: Pointer to the size of the buffer.
 * @spe_char: Format specifier character ('o', 'u', 'x', etc.).
 * Return: None.
 */
void print_uintX(va_list args, char *buffer, int *buffer_index,
int *buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);

	write_integerX(&buffer, buffer_index, num, 16, buffer_size);
}
/**
 * write_integerX -  Writes an integer to the buffer.
 *
 * @buffer: Pointer to the buffer.
 * @index: Pointer to the current index in the buffer.
 * @num: Integer to write.
 * @base: Base for conversion (e.g., 10 for decimal).
 * @size: Pointer to the size of the buffer.
 */
void write_integerX(char **buffer, int *index, long num, int base, int *size)
{
	char temp[1000];
	int i = 0;

	if (num == 0)
	{
		write_char(buffer, index, '0', size);
		return;
	}
	if (num < 0)
	{
		write_char(buffer, index, '-', size);
		num = -num;
	}
	while (num > 0)
	{
		int digit = num % base;

		temp[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';/*e*/
		num /= base;
	}
	while (i > 0)
	{
		write_char(buffer, index, temp[--i], size);
	}
}
