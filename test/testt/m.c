#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define INITIAL_BUFFER_SIZE 1024

void write_char(char **buffer, int *index, char c, int *size) 
{
	if (*index >= *size - 1) {
		*size *= 2;
		char *new_buffer = (char *)malloc(*size);
		if (new_buffer == NULL) {
			// Handle memory allocation failure
			free(*buffer);
			exit(-1);
		}
		// Copy the contents to the new buffer
		for (int i = 0; i < *index; i++) {
			new_buffer[i] = (*buffer)[i];
		}
		free(*buffer);
		*buffer = new_buffer;
	}
	(*buffer)[(*index)++] = c;
}

void write_string(char **buffer, int *index, const char *str, int *size) {
	while (*str != '\0') {
		write_char(buffer, index, *str++, size);
	}
}

void write_integer(char **buffer, int *index, long num, int base, int *size) {
	char temp[20];
	int i = 0;

	if (num == 0) {
		write_char(buffer, index, '0', size);
		return;
	}

	if (num < 0) {
		write_char(buffer, index, '-', size);
		num = -num;
	}

	while (num > 0) {
		int digit = num % base;
		temp[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
		num /= base;
	}

	while (i > 0) {
		write_char(buffer, index, temp[--i], size);
	}
}

int _printf(const char *format, ...) {
	va_list args;
	va_start(args, format);

	char *buffer = (char *)malloc(INITIAL_BUFFER_SIZE);
	if (buffer == NULL) {
		va_end(args);
		exit(-1); // Handle memory allocation failure
	}

	int buffer_size = INITIAL_BUFFER_SIZE;
	int buffer_index = 0;

	while (*format != '\0') {
		if (buffer_index >= buffer_size - 1) {
			write_char(&buffer, &buffer_index, '\0', &buffer_size); // Null-terminate the buffer temporarily
			char *new_buffer = (char *)malloc(buffer_size * 2);
			if (new_buffer == NULL) {
				// Handle memory allocation failure
				free(buffer);
				va_end(args);
				exit(-1);
			}
			// Copy the contents to the new buffer
			for (int i = 0; i < buffer_index; i++) {
				new_buffer[i] = buffer[i];
			}
			free(buffer);
			buffer = new_buffer;
		}

		if (*format == '%') {
			format++;
			switch (*format) {
				case 's': {
					const char *str = va_arg(args, const char *);
					write_string(&buffer, &buffer_index, str, &buffer_size);
					break;
				}
				case 'c': {
					char c = (char)va_arg(args, int);
					write_char(&buffer, &buffer_index, c, &buffer_size);
					break;
				}
				case '%':
					write_char(&buffer, &buffer_index, '%', &buffer_size);
					break;
				case 'i':
				case 'd': {
					int num = va_arg(args, int);
					write_integer(&buffer, &buffer_index, num, 10, &buffer_size);
					break;
				}
				case 'u': {
					unsigned int num = va_arg(args, unsigned int);
					write_integer(&buffer, &buffer_index, num, 10, &buffer_size);
					break;
				}
				case 'o': {
					unsigned int num = va_arg(args, unsigned int);
					write_integer(&buffer, &buffer_index, num, 8, &buffer_size);
					break;
				}
				case 'x': {
					unsigned int num = va_arg(args, unsigned int);
					write_integer(&buffer, &buffer_index, num, 16, &buffer_size);
					break;
				}
				case 'X': {
					unsigned int num = va_arg(args, unsigned int);
					write_integer(&buffer, &buffer_index, num, 16, &buffer_size);
					break;
				}
			}
		} else {
			write_char(&buffer, &buffer_index, *format, &buffer_size);
		}

		format++;
	}

	buffer[buffer_index] = '\0';
	write(STDOUT_FILENO, buffer, buffer_index);

	va_end(args);
	free(buffer);
	return buffer_index;
}

int main(void) {
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)LONG_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	printf("Len:[%d]\n", len2);

	return 0;
}
