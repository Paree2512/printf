#include "main.h"

/**
 * get_size - This will calculate the size to cast the argument
 * @format: Formatted string to print the arguments
 * @x: Arguments to be printed
 *
 * Return: Precision.
 */
int get_size(const char *format, int *x)
{
	int cur_x = *x + 1;
	int size = 0;

	if (format[cur_x] == 'l')
		size = S_LONG;
	else if (format[cur_x] == 'h')
		size = S_SHORT;

	if (size == 0)
		*x = cur_x - 1;
	else
		*x = cur_x;

	return (size);
}
