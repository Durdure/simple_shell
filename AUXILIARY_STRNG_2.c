#include "main.h"

/**
 * rev_string - reverses a string.
 * @stng: input string.
 *
 * Return: no return.
 */
void rev_string(char *strng)
{
	int count = 0, i, j;
	char *s, temp;

	while (count >= 0)
	{
		if (strng[count] == '\0')
			break;
		count++;
	}
	s = strng;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(s + j);
			*(s + j) = *(s + (j - 1));
			*(s + (j - 1)) = temp;
		}
	}
}

