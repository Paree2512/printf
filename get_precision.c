#include "main.h"

/**
 * get_precision - this function calculated the precision
 * @format: used to print the arguments in formatted string
 * @x: list of arguments to print
 * @list: arguments list
 * Return: to return the precision
 */
int get_precision(const char *format, int *x, va_list list)
{
	int cur_x = *x + 1;
	int precision = -1;

	if (format[cur_x] != '.')
		return (precision);

	precision = 0;

	for (cur_x += 1; format[cur_x] != '\0'; cur_x++)
	{
		if (is_digit(format[cur_x]))
		{
			precision *= 10;
			precision += format[cur_x] - '0';
		}
		else if (format[cur_x] == '*')
		{
			cur_x++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*x = cur_x - 1;

	return (precision);
}
