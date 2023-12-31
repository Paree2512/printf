#include "main.h"
/**
 * handle_print - This prints arguments based on its type
 * @frmt: Formatted string to print the arguments
 * @list: Arguments to be printed
 * @ind: ind
 * @buffer: Buffer array that handles print
 * @flags: This calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *frmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int x, unknow_len = 0, printed_chars = -1;
	frmt_t frmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (x = 0; frmt_types[x].frmt != '\0'; x++)
		if (frmt[*ind] == frmt_types[x].frmt)
			return (frmt_types[x].fn(list, buffer, flags, width, precision, size));

	if (frmt_types[x].frmt == '\0')
	{
		if (frmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (frmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (frmt[*ind] != ' ' && frmt[*ind] != '%')
				--(*ind);
			if (frmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &frmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
