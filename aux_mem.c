#include "main.h"

/**
 * _memcpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
    char *d = (char *)newptr;
    const char *s = (const char *)ptr;
    
    for (unsigned int i = 0; i < size; i++) {
        d[i] = s[i];
    }
}
/**
 * _realloc - dynamically reallocates a memory block.
 * @ptr: pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    
    if (ptr == NULL) {
        return malloc(new_size);
    }
    
    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }
    
    unsigned int copy_size = old_size;
    if (new_size < old_size) {
        copy_size = new_size;
    }
    
    _memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    
    return new_ptr;
}

/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size) {
    return (char **)_realloc(ptr, old_size * sizeof(char *), new_size * sizeof(char *));
}
