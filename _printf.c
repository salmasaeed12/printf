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
	if (*str == '\0')
		return (str);
	*str = va_arg(*ar, int);
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
	int i, len_buf, size_buf;
	spe spes[] = {
		{"s", p_string},
		{"%", _percent},
		{"c", p_char},
		{NULL, NULL}
	};
	char *buffer, *ptrb;
	va_list ar;

	if (!format)
		return (0);
	size_buf = 1024;
	buffer = malloc(sizeof(char)  *  size_buf);
	if (buffer == NULL)
		return (0);
	ptrb = buffer;
	va_start(ar, format);
	for (; *format != '\0'; format++, ptrb++)
	{
		len_buf = ptrb - buffer;
		if (len_buf == size_buf - 1)
			ptrb = change_len(&size_buf, ptrb, buffer, len_buf);
		if (*format == '%')
		{
			format++;
			for (i = 0; spes[i].spe_char; i++)
				if (*format == spes[i].spe_char[0])
					ptrb = spes[i].func(ptrb, &ar);
		}
		else
			*ptrb = *format;
	}
	*ptrb = '\0';
	write(1, buffer, i = _strlen(buffer));
	va_end(ar);
	free(buffer);
	return (i);
}
