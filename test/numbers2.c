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
/**
 * pp_o - Store a string
 *
 * @pb: Pointer to buffer
 * @ar: The list of arguments
 * @size: pointer to size
 * @buf: Pointer to buffer
 * @len_buf: Check if buffer is full or not
 * Return: the next address
 */
char *pp_o(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buffer_index;

	buffer_index = pb - *buf;/*e*/
	(void)(len_buf);
	print_uinto(*ar/*e*/, *buf/*e*/, &buffer_index/*e*/, size);
	return ((buffer_index - 1) + *buf);
}
/**
 * pp_u - Store a string
 *
 * @pb: Pointer to buffer
 * @ar: The list of arguments
 * @size: pointer to size
 * @buf: Pointer to buffer
 * @len_buf: Check if buffer is full or not
 * Return: the next address
 */
char *pp_u(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buffer_index;

	buffer_index = pb - *buf;/*e*/
	(void)(len_buf);
	print_uintu(*ar/*e*/, *buf/*e*/, &buffer_index/*e*/, size);
	return ((buffer_index - 1) + *buf);
}
/**
 * pp_x - Store a string
 *
 * @pb: Pointer to buffer
 * @ar: The list of arguments
 * @size: pointer to size
 * @buf: Pointer to buffer
 * @len_buf: Check if buffer is full or not
 * Return: the next address
 */
char *pp_x(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buffer_index;

	buffer_index = pb - *buf;/*e*/
	(void)(len_buf);
	print_uintx(*ar/*e*/, *buf/*e*/, &buffer_index/*e*/, size);
	return ((buffer_index - 1) + *buf);
}
/**
 * pp_X - Store a string
 *
 * @pb: Pointer to buffer
 * @ar: The list of arguments
 * @size: pointer to size
 * @buf: Pointer to buffer
 * @len_buf: Check if buffer is full or not
 * Return: the next address
 */
char *pp_X(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buffer_index;

	buffer_index = pb - *buf;/*e*/
	(void)(len_buf);
	print_uintX(*ar/*e*/, *buf/*e*/, &buffer_index/*e*/, size);
	return ((buffer_index - 1) + *buf);
}
