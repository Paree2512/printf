#include "main.h"

/**
 * is_printable - This will evaluate if a char is printable
 * @c: Char to evaluate
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Appends ascci in hexadecimal code to buffer
 * @buffer: Array of chars
 * @x: Index where appending starts.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int x)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[x++] = '\\';
	buffer[x++] = 'x';

	buffer[x++] = map_to[ascii_code / 16];
	buffer[x] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - This comfirms if a char is a digit
 * @c: Char to evaluate
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts numbers to specified sizes
 * @numb: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of numb
 */
long int convert_size_number(long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * convert_size_unsgnd - Casts numbers to specified sizes
 * @numb: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of numb
 */
long int convert_size_unsgnd(unsigned long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((unsigned short)numb);

	return ((unsigned int)numb);
}
