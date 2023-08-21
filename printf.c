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

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	for (nm = 0; format[nm] != '\0'; nm++)
	{
		if (format[nm] != '%')
			_XcHar(format[nm]);
		else if (format[nm] == '%' && format[nm  + 1] == 'c')
		{
			_XcHar(va_arg(args, int));
			nm++;
		}
		else if (format[nm] == '%' && format[nm + 1] == 's')
		{
		string_count = makes(va_arg(args, char*));
		nm++;
		count += (string_count - 1);
		}
		else if (format[nm] == '%' && format[nm + 1] == '%')
		{
		_XcHar('%');
		nm++;
		}
	count += 1;
	}

	va_end(args);

	return (count);
}
