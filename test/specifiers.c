#include "main.h"

/**
 * store_buffer -  Resizes the buffer if necessary
 *   to accommodate a new element at buffer_index.
 *
 * @buffer: Pointer to the buffer.
 * @buffer_size: Pointer to the size of the buffer.
 * @buffer_index: Index where the new element will be added.
 * Return: 0 on success, -1 on failure.
 */
int store_buffer(char *buffer, int *buffer_size, int buffer_index)
{
	int i = 0;

	if (buffer_index > *buffer_size - 1)
	{
		char *new_buffer = (char *)malloc(2 * (*buffer_size));
		*buffer_size *= 2;

		while (i < buffer_index)
		{
			new_buffer[i] = buffer[i];
			i++;
		}
		new_buffer[i] = '\0';
		free(buffer);

		buffer = (char *)malloc(*buffer_size);

		if (buffer == NULL)
			return (-1);
		{
			i = 0;
			while (i < buffer_index)
			{
				buffer[i] = new_buffer[i];
				i++;
			}
		}
		buffer[i] = '\0';
		free(new_buffer);
	}
	return (0);
}
/**
 * print_int - a function Prints an integer to the buffer.
 * Description: a function Prints an integer to the buffer.
 * @args: Variable argument list.
 * @buffer: Pointer to the buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 * @buffer_size: Pointer to the size of the buffer.
 * Return: None.
 */
void print_int(va_list args, char *buffer, int *buffer_index,
int *buffer_size)
{
	int num = va_arg(args, int);/*e*/

	write_integer(&buffer, buffer_index, num/*e*/, 10, buffer_size);
}
/**
 * write_integer -  Writes an integer to the buffer.
 *
 * @buffer: Pointer to the buffer.
 * @index: Pointer to the current index in the buffer.
 * @num: Integer to write.
 * @base: Base for conversion (e.g., 10 for decimal).
 * @size: Pointer to the size of the buffer.
 */
void write_integer(char **buffer, int *index, long num, int base, int *size)
{
	char temp[20];
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

		temp[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';/*e*/
		num /= base;
	}
	while (i > 0)
	{
		write_char(buffer, index, temp[--i], size);
	}
}
/**
 * write_char -  a character to the buffer.
 *
 * @buffer: Pointer to the buffer.
 * @index: Pointer to the current index in the buffer.
 * @c: Character to write.
 * @size: Pointer to the size of the buffer.
 */
void write_char(char **buffer, int *index, char c, int *size)
{
	char *new_buffer;
	int i;

	if (*index >= *size - 1)
	{
		*size *= 2;

		new_buffer  = (char *)malloc(*size);/*e*/
		if (new_buffer == NULL)
		{
			free(*buffer);
			return;/*e*/
		}
		for (i = 0; i < *index; i++)
		{
			new_buffer[i] = (*buffer)[i];
		}
		free(*buffer);
			*buffer = new_buffer;
	}
	(*buffer)[(*index)++] = c;
	/*(*buffer)[*index] = '\0';e*/
}
