#include "main.h"
/**
 * _printf - produces output according to a format
 * @format:  is a character string
 * Return: number of bytes
 */
int _printf(const char *format, ...)
{
	unsigned int count = 0;
	unsigned int nm, string_count;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	for (nm = 0; format[nm] != '\0'; nm++)
	{

		if (format[nm] == '%' && format[nm + 1] == 'c')
		{
			_XcHar(va_arg(args, int));
			nm++;
		}
		else if (format[nm] == '%' && format[nm + 1] == 's')
		{
			char *string = va_arg(args, char *);
			string_count = makes(string);
			nm++;
			count += string_count;
		}
		else if (format[nm] == '%' && format[nm + 1] == '%')
		{
			_XcHar('%');
			nm++;
		}
		else if (format[nm] == '%' && (format[nm + 1] == 'd' || format[nm + 1] == 'i'))
		{
			int number = va_arg(args, int);
			int digit, temp, divider, i, j;

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
				divider *= 10;
			for (j = 0; j < digit; j++)
			{
				_XcHar((temp / divider) + '0');
				temp %= divider;
				divider /= 10;
			}
			nm++;
		}
		else
		{
			_XcHar(format[nm]);
		}
		count++;
	}

	va_end(args);

	return (count);
}
