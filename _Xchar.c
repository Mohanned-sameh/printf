#include "main.h"
/**
 * _XcHar - prints to stdout
 * @c: the char to be printed
 * Return: 1
 */
int _XcHar(char c)
{
	write(1, &c, 1);
}
