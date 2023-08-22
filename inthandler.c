#include "main.h"
/**
 * inthandler - prints ints
 * @number: the number to be printed
 */
void inthandler(int number)
{
	int divider, digit, temp, i, j;

	if (number < 0)
	{
		_XcHar('-');
		number = -number;
	}

	digit = 0;
	temp = number;

	while (temp != 0)
	{
		temp /= 10;
		digit++;
	}

	temp = number;
	divider = 1;

	for (i = 1; i < digit; i++)
	{
		divider *= 10;
	}
	for (j = 0; j < digit; j++)
	{
		_XcHar((temp / divider) + '0');
		temp %= divider;
		divider /= 10;
	}
}
