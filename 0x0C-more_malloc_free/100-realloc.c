#include <stdlib.h>
#include <string.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory block to reallocate
 * @old_size: The size of the allocated space for ptr
 * @new_size: The new size of the memory block
 *
 * Return: Pointer to the reallocated memory block
 *         NULL if new_size is 0 and ptr is not NULL, or if malloc fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size < old_size)
		old_size = new_size;

	memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return (new_ptr);
}
