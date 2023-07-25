#include "main.h"

/**
 * get_flags - The calculates active flags
 * @format: Formatted string to print the arguments
 * @x: takes a parameter
 * Return: Flags:
 */
int get_flags(const char *format, int *x)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, cur_x;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_x = *x + 1; format[cur_x] != '\0'; cur_x++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[cur_x] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*x = cur_x - 1;

	return (flags);
}
