#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - a function that produces output according to format
 *@format: String
 * Return: 0 (Success)
 */
int _printf(const char *format, ...)
{
	va_list f_store;
	va_start(f_store, format);
	int a;
	int num_store = 0;

	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			putchar(format[a]);
			num_store++;
		}
		else
		{
			a++;
			switch (format[a])
			{
				case 'c':
					char c = va_arg(f_store, int);

					putchar(c);
					num_store++;

					break;
				case 's':
					char *str;
					str = va_arg(f_store, char *);

					int b;

					for (b = 0; str[b] != '\0'; b++);
					{

						putchar(str[b]);
						num_store++;
						break;
					}

				case '%':

					putchar('%');
					num_store++;
					break;

				default:
					putchar('%');
					putchar(format[a]);
					num_store = num_store + 2;
			}
		}
	}
	va_end(f_store);

	return (num_store);
}
