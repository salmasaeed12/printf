#include "main.h"

void check_case(int *buffer_index, int *buffer_size, char **buffer, const char *format, va_list *args)
{
	if (*format == '%')
	{
		format++;
		switch (*format)
		{
		case 's':
		{
			const char *str = va_arg(*args, const char *);
			write_string(buffer, buffer_index, str, buffer_size);
			break;
		}
		case 'c':
		{
			char c = (char)va_arg(*args, int);
			write_char(buffer, buffer_index, c, buffer_size);
			break;
		}
		case '%':
			write_char(buffer, buffer_index, '%', buffer_size);
			break;
		case 'i':
		case 'd':
		{
			int num = va_arg(*args, int);
			write_integer(buffer, buffer_index, num, 10, buffer_size);
			break;
		}
		case 'u':
		{
			unsigned int num = va_arg(*args, unsigned int);
			write_integer(buffer, buffer_index, num, 10, buffer_size);
			break;
		}
		case 'o':
		{
			unsigned int num = va_arg(*args, unsigned int);
			write_integer(buffer, buffer_index, num, 8, buffer_size);
			break;
		}
		case 'x':
		case 'X':
		{
			unsigned int num = va_arg(*args, unsigned int);
			write_integer(buffer, buffer_index, num, 16, buffer_size);
			break;
		}
		}
	}
	else
	{
		write_char(buffer, buffer_index, *format, buffer_size);
	}

	(*args)++;
}

// The rest of your code remains unchanged


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

void write_char(char **buffer, int *index, char c, int *size)
{
	if (*index >= *size - 1)
	{
		*size *= 2;
		char *new_buffer = (char *)malloc(*size);
		if (new_buffer == NULL)
		{
			free(*buffer);
			exit(-1);
		}

		// Copy the contents manually
		for (int i = 0; i < *index; i++)
		{
			new_buffer[i] = (*buffer)[i];
		}

		free(*buffer);
		*buffer = new_buffer;
	}
	(*buffer)[(*index)++] = c;
	(*buffer)[*index] = '\0'; // Null-terminate the string
}

void write_string(char **buffer, int *index, const char *str, int *size)
{
	while (*str != '\0')
	{
		write_char(buffer, index, *str++, size);
	}
}
#include "main.h"

void check_case(int *buffer_index, int *buffer_size, char **buffer, const char *format, va_list *args)
{
	if (*format == '%')
	{
		format++;
		switch (*format)
		{
		case 's':
		{
			const char *str = va_arg(*args, const char *);
			write_string(buffer, buffer_index, str, buffer_size);
			break;
		}
		case 'c':
		{
			char c = (char)va_arg(*args, int);
			write_char(buffer, buffer_index, c, buffer_size);
			break;
		}
		case '%':
			write_char(buffer, buffer_index, '%', buffer_size);
			break;
		case 'i':
		case 'd':
		{
			int num = va_arg(*args, int);
			write_integer(buffer, buffer_index, num, 10, buffer_size);
			break;
		}
		case 'u':
		{
			unsigned int num = va_arg(*args, unsigned int);
			write_integer(buffer, buffer_index, num, 10, buffer_size);
			break;
		}
		case 'o':
		{
			unsigned int num = va_arg(*args, unsigned int);
			write_integer(buffer, buffer_index, num, 8, buffer_size);
			break;
		}
		case 'x':
		case 'X':
		{
			unsigned int num = va_arg(*args, unsigned int);
			write_integer(buffer, buffer_index, num, 16, buffer_size);
			break;
		}
		}
	}
	else
	{
		write_char(buffer, buffer_index, *format, buffer_size);
	}

	(*args)++;
}

// The rest of your code remains unchanged


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

void write_char(char **buffer, int *index, char c, int *size)
{
	if (*index >= *size - 1)
	{
		*size *= 2;
		char *new_buffer = (char *)malloc(*size);
		if (new_buffer == NULL)
		{
			free(*buffer);
			exit(-1);
		}

		// Copy the contents manually
		for (int i = 0; i < *index; i++)
		{
			new_buffer[i] = (*buffer)[i];
		}

		free(*buffer);
		*buffer = new_buffer;
	}
	(*buffer)[(*index)++] = c;
	(*buffer)[*index] = '\0'; // Null-terminate the string
}

void write_string(char **buffer, int *index, const char *str, int *size)
{
	while (*str != '\0')
	{
		write_char(buffer, index, *str++, size);
	}
}
