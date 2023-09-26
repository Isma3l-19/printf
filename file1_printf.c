#include <stdio.h>
#include <stdarg.h>
/**
 * print_char - function to print a character
 * @s: character to print
 * @num_tally: pointer to the character count
 */
void print_char(char s, int *num_tally)
{
        putchar(s);
        (*num_tally)++;
}
/**
 * print_str - function to print a string
 * @str: String to print
 * @num_tally: pointer to the character count
 */
void print_str(const char *str, int *num_tally)
{
        int i = 0;

        while (str[i] != '\0')
        {
                putchar(str[i]);
                (*num_tally)++;
                i++;
        }
}
/**
 * _printf - a function that produces output according to format
 * @format: string
 * Return: characters to be printed
 */
int _printf(const char *format, ...)
{
        va_list f_store;

        int val_tally = 0, a = 0;

        va_start(f_store, format);
        while (format[a] != '\0')
        {
                if (format[a] != '%')
                {
                        print_char(format[a], &val_tally);
                }
                else
                {
                        a++;
                        if (format[a] == 'c')
                        {
                                char c = va_arg(f_store, int);

                                print_char(c, &val_tally);
                        }
                        else if (format[a] == 's')
                        {
                                char *str = va_arg(f_store, char *);

                                print_str(str, &val_tally);
                        }
                        else if (format[a] == '%')
                        {
                                print_char('%', &val_tally);
                        }
                        else
                        {
                                print_char('%', &val_tally);
                                print_char(format[a], &val_tally);
                        }
                } a++;
        }
        va_end(f_store);
        return (val_tally);
}
/**
 * print_int - a function that prints int
 * @types: lists of arguments
 * @buffer: buffer array to handle print_int
 * @flags:  calculates active flags in the function
 * @width: gets the  width
 * @precision: precision specification
 * @size: size specifier
 * Return: 0
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	{
		buffer[i--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

