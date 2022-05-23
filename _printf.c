#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints a character to te stdout
 * @format: The format containing directives and specifers
 *
 * Return: On success count (the number of characters printed)
 */
int _printf(const char *format, ...)
{
	va_list aq;
	char l;
	int k, n, count;
	char *m;

	k = count = 0;
	va_start(aq, format);
	for (k = 0; format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			if ((format[k] != 'c') && (format[k] != 's'))
			{
				_putchar(format[k]);
				count++;
			}
		}
		else
		{
			if (format[k] == '%' && format[k + 1] == 'c')
			{
				l = va_arg(aq, int);
				_putchar(l);
				count++;
			}
			if (format[k] == '%' && format[k + 1] == 's')
			{
				m = va_arg(aq, char*);
				for (n = 0; m[n] != '\0'; n++)
				{
					_putchar(m[n]);
					count++;
				}
			}
		}
	}
	va_end(aq);
	return (count);
}
