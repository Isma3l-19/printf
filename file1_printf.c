#include "main.h"
#include <stdarg.h>
#include <string.h>
/**
 * _printf -  a function that produces output according to format
 * @format: pointer to char
 * Return: 0 (Success)
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	
	int store = 0;
	
	while (*format != '\0' && *format == '%s' && * format == '%c' && *format == '%%')
	{
		return (0);
	}
	store += strlen(va_arg(args, char *format));
	return (0);
}
