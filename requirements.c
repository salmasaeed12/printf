#include "main.h"

/**
 * change_len - change the length of buffer
 *
 * @size_buf: point to the last sace
 * @pb: last address
 * @buffer: The buffer
 * @len_buf: The length
 * Return: The new space
*/
char *change_len(int *size_buf, char *pb, char *buffer, int len_buf)
{
	int j;

	j = *size_buf;
	buffer = _realloc(buffer, j, *size_buf = 1024 + *size_buf);
	if (buffer == NULL)
		return (NULL);
	pb = buffer + len_buf;
	return (pb);
}
/**
 * _realloc - reallocate the memory block
 *
 * @ptr: the previously block
 * @old_size: the old_size of the block
 * @new_size: the new_size of the block
 * Return: the new block
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *poi;
	unsigned int j;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	poi = malloc(new_size);
	if (poi == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		if (new_size > old_size)
		{
			for (j = 0; j < old_size; j++)
				*((char *)poi + j) = *((char *)ptr + j);
		}
		if (new_size < old_size)
		{
			for (j = 0; j < new_size; j++)
				*((char *)poi + j) = *((char *)ptr + j);
		}
		if (new_size == old_size)
		{
			free(poi);
			return (ptr);
		}
		free(ptr);
	}
	return (poi);
}
