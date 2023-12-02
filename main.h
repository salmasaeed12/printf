#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct special - the selector struct
 * @spe_char: The special character
 * @func: Point to function
 *
 * Description: Correspond the special character with it's function
*/
typedef struct special
{
	char *spe_char;
	char *(*func)();
} spe;
char *change_len(int *size_buf, char *pb, char *buffer, int len_buf);
char *p_string(char *buffer, va_list *ar);
char *_percent(char *str, va_list *ar);
int _strlen(char *str);
int _printf(const char *format, ...);
char *p_char(char *str, va_list *ar);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif/*endif*/
