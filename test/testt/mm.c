#include "main.h"
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	char *buffer = (char *)malloc(INITIAL_BUFFER_SIZE);
	if (buffer == NULL)
	{
		va_end(args);
		return -1;
	}

	int buffer_size = INITIAL_BUFFER_SIZE;
	int buffer_index = 0;

	while (*format != '\0')
	{
		if (buffer_index >= buffer_size - 1)
		{
			buffer_size *= 2;
			char *new_buffer = (char *)malloc(buffer_size);
			if (new_buffer == NULL)
			{
				free(buffer);
				va_end(args);
				return -1;
			}

			for (int i = 0; i < buffer_index; i++)
			{
				new_buffer[i] = buffer[i];
			}

			free(buffer);
			buffer = new_buffer;
		}
		check_case(buffer_index, buffer_size, buffer, format, &args);
		format++;
	}

	write(STDOUT_FILENO, buffer, buffer_index);

	va_end(args);
	return buffer_index;
}

int main(void)
{
	int len;
	int len2;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Negative:[%d]\n", -762534);
	len2 = printf("Negative:[%d]\n", -762534);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Unsigned:[%u]\n", UINT_MAX + 1024);
	len2 = printf("Unsigned:[%u]\n", UINT_MAX + 1024);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Unsigned octal:[%o]\n", UINT_MAX + 1024);
	len2 = printf("Unsigned octal:[%o]\n", UINT_MAX + 1024);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Unsigned hexadecimal:[%x, %X]\n", UINT_MAX + 1024, UINT_MAX + 1024);
	len2 = printf("Unsigned hexadecimal:[%x, %X]\n", UINT_MAX + 1024, UINT_MAX + 1024);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	printf("Len:[%d, %d]\n", len, len2);

	return (0);
}
