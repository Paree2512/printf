#include "main.h"

/**
 * print_pointer - this function prints the value
 * of a pinter variable
 * @types: arguments list
 * @buffer: array of buffer to handle the print
 * @flags: this is used to calculate the active flags
 * @width: to get the width
 * @precision: to specify the precision
 * @size: to specify the ize
 * Return: to return the number of printed chars
 */
int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char extra_c = 0, padd = '';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = '', length++;

	ind++;

	return (write_pointer(buffer, ind, length, width,
				flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - this function prints ascii codes in hexa
 * of non printable characters
 * @types: arguments list
 * @buffer: array of buffer to handle print
 * @flags: used to calculate active flags
 * @width: to get the width
 * @precision: specifies the precision
 * @size: specifies the size
 * Return: to return the number of printed characters
 */
int print_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int x = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[x] != '\0')
	{
		if (is_printable(str[x]))
			buffer[x + offset] = str[x];
		else
			offset += append_hexa_code(str[x], buffer, x + offset);

		x++
	}

	buffer[x + offset] = '\0';

	return (write(1, buffer, x + offset));
}

/**
 * print_reverse - this function prints string in reverse
 * @types: arguments list
 * @buffer: array buffer to handle the print
 * @flags: used to calculate the active flags
 * @width: to get the width
 * @precision: specifies the precision
 * @size: specifies the size
 * Return: to return the number of printed characters
 */
int print_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char *str;
	int x, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}

	for (x = 0; str[x]; x++)
		for (x = x - 1; x >= 0; x--)
		{
			char z = str[x];

			write(1, &z, 1);
			count++;
		}
	return (count);
}

/**
 * print_rot13string - this function prints a string in rot13
 * @types: argument list
 * @buffer: array of buffer to handle print
 * @flags: used to calculate the active flags
 * @width: to get the width
 * @precision: specifies the precision
 * @size: specifies the size
 * Return: to return the number of printed characters
 */
int print_rot13string(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
