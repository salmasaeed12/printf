#include <main.h>
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
else
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
int print_int(va_list args, char *buffer, int *buffer_index, int *buffer_size)
{
int num = va_arg(args, int);
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
void print_uint(va_list args, char *buffer, int *buffer_index,
int *buffer_size, char spe_char)
{
unsigned int num = va_arg(args, unsigned int);
if (spe_char == 'o')
write_integer(&buffer, buffer_index, num, 8, buffer_size);
else if (spe_char == 'u')
write_integer(&buffer, buffer_index, num, 10, buffer_size);
else if (spe_char == 'X' || spe_char == 'x')
write_integer(&buffer, buffer_index, num, 16, buffer_size);
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
temp[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
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
if (*index >= *size - 1)
{
*size *= 2;
char *new_buffer = (char *)malloc(*size);
if (new_buffer == NULL)
{
free(*buffer);
return (-1);
}
for (int i = 0; i < *index; i++)
{
new_buffer[i] = (*buffer)[i];
}
free(*buffer);
*buffer = new_buffer;
}
(*buffer)[(*index)++] = c;
(*buffer)[*index] = '\0';
}
