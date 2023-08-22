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

	if (format == NULL)
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
			string_count = makes(va_arg(args, char *));
			nm++;
			count += string_count;
		}
		else if (format[nm] == '%' && format[nm + 1] == '%')
		{
			_XcHar('%');
			nm++;
		}
		else if (format[nm] == '%' && (format[nm + 1] == 'd'
					|| format[nm + 1] == 'i'))
		{
			int number = va_arg(args, int);

			inthandler(number);
			nm++;
		}
		else
			_XcHar(format[nm]);
		count++;
	}
	va_end(args);
	return (count);
}
