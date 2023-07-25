#include "main.h"

/**
 * get_width - this function calculated the width
 * @format: formatted string for the printing of arguments
 * @x: arguments list to be printed
 * @list: arguments list
 * Return: to return the width
 */
int get_width(const char *format, int *x, va_list list)
{
	int cur_x;
	int width =  0;

	for (cur_x = *x + 1; format[cur_x] != '\0'; cur_x++)
	{
		if (is_digit(format[cur_x]))
		{
			width *= 10;
			width += format[cur_x] - '0';
		}
		else if (format[cur_x] == '*')
		{
			cur_x++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*x = cur_x - 1;

	return (width);
}
