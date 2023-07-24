#include "include main.h"
/**
 * print_unsigned - This function prints an unsigned number
 * @types: this is for list of arguments
 * @buffer: Buffer array to handle the print
 * @flags: used to calculate the active flags
 * @width: to get the width
 * @precision: specifies the precision
 * @size: specifies the size
 * Return: to return the number of printed chars
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[x--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[x--] = (numb % 10) + '0';
		numb /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/**
 * print_octal - this function prints an unsigned number
 * in octal notation
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: used to calculate active flags
 * @width: to get the width
 * @precision: specifies the precision
 * @size: specifies the size
 * Return: to return the number of printed chars
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_num = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[x--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[x--] = '0';

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/**
 * print_hexa_upper - this function prints an unsigned number
 * in uper hexadecimal notation
 * @types: arguments list
 * @buffer: buffer array to handle the print
 * @flags: used to calculate active flags
 * @width: to get the width
 * @precision: specifies the precision
 * @size: specifies the size
 * Return: to return the number of printed chars
 */
int print_hexa_upper(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags,
				'X', width, precision, size));
}

/**
 * print_hexa - a function that prints hexadecimal number
 * in lower or upper
 * @types: list of arguments
 * @map_to: used to map the number to array of values
 * @buffer: buffer array to handle the print
 * @flags: used to calculate active flags
 * @width: to get the width
 * @precision: specifies the precision
 * @size: specifies the size
 * Return: to return the number of printed chars
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_num = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[x--] = map_to[numb % 16];
		numb /= 16;
	}

	if (flags & F_HASH && inti_num != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
