#include "main.h"
/**
 * makes - print string
 * @c: string
 * Return: num of bytes
 */
int makes(char *c)
{
	int count;

	count = 0;

	if (c)
	{
		while (c[count] != '\0')
		{
			_XcHar(c[count]);
			count++;
		}
	}
	return (count);
}
