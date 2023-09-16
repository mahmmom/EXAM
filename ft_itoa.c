#include <stdlib.h>

static int	num_digit(long num)
{
	int	digit;

	digit = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		digit++;
	while (num != 0)
	{
		num = num / 10;
		digit++;
	}
	return (cur);
}

char	*ft_itoa(int n)
{
	long	len;
	long	num;
	char	*result;

	len = num_digit(n);
	num = n;
	if (n < 0)
		num *= -1;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = 0;
	if (num == 0)
		result[0] = '0';
	else
	{
		while (len--, num != 0)
		{
			result[len] = (num % 10) + '0';
			num = (num - (num % 10)) / 10;
		}
		if (n < 0)
			result[len] = '-';
	}
	return (result);
}
