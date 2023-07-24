#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @sourc: const char pointer the source of str
 * 
 * Return: the dest
 */
char *_str_cat(char *dest, const char *sourc)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; sourc[j] != '\0'; j++)
	{
		dest[i] = sourc[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * *_strcpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @sourc: Type char pointer the source of str
 * 
 * Return: the dest.
 */
char *_strcpy(char *dest, char *sourc)
{

	size_t a;

	for (a = 0; sourc[a] != '\0'; a++)
	{
		dest[a] = sourc[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _str_cmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 *
 * Return: Always 0.
 */
int _str_cmp(char *s1, char *s2)
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
 * _str_chr - locates a character in a string,
 * @s: string.
 * @c: character.
 *
 * Return: the pointer to the first occurrence of the character c.
 */
char *_str_chr(char *s, char c)
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
 * _str_spn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accpt: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _str_spn(char *s, char *accpt)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accpt + j) != '\0'; j++)
		{
			if (*(s + i) == *(accpt + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}

