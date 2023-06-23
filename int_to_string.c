#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
				       char *buff, int buff_size);

/**
 * get_int - Converts an integer to a string.
 * @num: The number to convert.
 * 
 * Return: A newly allocated string containing the converted number.
 *         NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;
	
	temp = _abs(num);
	length = get_numbase_len(temp, 10);
	if (num < 0 || num_l < 0)
		length++; /* Add space for negative sign */
	ret = malloc(length + 1); /* Allocate memory for the string */
	if (!ret)
		return (NULL);
	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';
	return (ret);
}

/**
 * _abs - Gets the absolute value of an integer.
 * @i: The integer to get the absolute value of.
 *
 * Return: The unsigned integer absolute value of i.
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Gets the length of a buffer needed for an unsigned int.
 * @num: The number to get the length needed for.
 * @base: The base of the number representation used by the buffer.
 *
 * Return: The integer length of the buffer needed (doesn't contain null byte).
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* All numbers contain at least one digit */
	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - Fills a buffer with correct numbers up to base 36.
 * @num: The number to convert to a string given the base.
 * @base: The base of the number used in the conversion (up to base 36).
 * @buff: The buffer to fill with the result of the conversion.
 * @buff_size: The size of the buffer in bytes.
 *
 * Return: Always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* Return lowercase ASCII value representation */
			buff[i] = rem + 87; /* 10 will be 'a', 11 will be 'b', ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
