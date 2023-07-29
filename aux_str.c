#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: the dest
 */
char *_strcat(char *dest, const char *src) {
    char *ptr = dest;
    
    while (*ptr != '\0') {
        ptr++;
    }
    
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    
    *ptr = '\0';
    
    return dest;
}

/**
 * *_strcpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src) {
    char *ptr = dest;
    
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    
    *ptr = '\0';
    
    return dest;
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
 * _strspn - gets the length of the initial segment of a string that consists of characters
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accept) {
    int count = 0;

    while (*s != '\0') {
        if (_strchr(accept, *s) == NULL) {
            return count;
        }

        count++;
        s++;
    }

    return count;
}
