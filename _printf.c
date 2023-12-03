#include "main.h"

/**
 * _percent - Print the percent
 *
 * @str: The address of cuurent buffer
 * @ar: The list of arguments
 * Return: The current address
 */
char *_percent(char *str, va_list *ar)
{
	*str = '%';
	(void)(ar);
	return (str);
}
/**
 * _strlen - Calculate the length
 *
 * @str: a string
 * Return: Length
 */
int _strlen(char *str)
{
	int n;

	for (n = 0; str[n] != '\0'; n++)
		;
	return (n);
}
/**
 * p_char - Store a character in buffer
 *
 * @str: The buffer
 * @ar: The list of arguments
 * Return: the current address
 */
char *p_char(char *str, va_list *ar)
{
	char c;

	c = va_arg(*ar, int);
	if (c == '\0')
		c = '\a';
	*str = c;
	return (str);
}
/**
 * p_string - Store a string
 *
 * @buffer: The buffer
 * @ar: The list of arguments
 * Return: the next address
 */
char *p_string(char *buffer, va_list *ar)
{
	char *str;
	int i;

	str = va_arg(*ar, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		buffer[i] = str[i];
	return (&buffer[i - 1]);
}
/**
 * _printf - like printf
 *
 * @format: The not ready string
 * Return: The number of chataters
 */
int _printf(const char *format, ...)
{
	int i, size_buf;/*len_buf*/
	spe *spes;
	char *buffer, *ptrb;
	const char *ptrf;
	va_list ar;

	ptrf = format;
	if (!format)
		return (0);

	size_buf = 1024;
	buffer = malloc(sizeof(char)  *  size_buf);
	if (buffer == NULL)
		return (0);
	ptrb = buffer;
	va_start(ar, format);
	ini_spes(&spes);/*Initialize the structure*/
	sbuf(ptrf, ptrb, buffer, &size_buf, &ar, spes);/*Store in the buffer*/
	write(1, buffer, i = _strlen(buffer));
	va_end(ar);
	free(spes);
	free(buffer);
	return (i);
}
