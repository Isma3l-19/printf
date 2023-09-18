#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - A function that produces output according to format
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list f_store;
	int i = 0;
	int num_store = 0;

	va_start(f_store, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			num_store++;
		}
		else
		{
			i++; /* Move past the '%'*/
			if (format[i] == 'c')
			{
				char c = va_arg(f_store, int); /* Fetch the character*/

				putchar(c);
				num_store++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(f_store, char *); /* Fetch the string*/

				printf("%s", str);
				num_store += strlen(str);
			}
			else if (format[i] == '%')
			{
				putchar('%');
				num_store++;
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				num_store += 2;
			}
		}
		i++; /* Move to the next character in the format string*/
	}
	va_end(f_store);
	return num_store;
}
/**
 * main - checks the printf function
 * Return: 0 (Success)
 */
int main(void)
{
	int check;

	check = _printf("Our first complex code\n");
	printf("Character count: %d\n", check);
	return (0);
}
