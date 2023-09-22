#include <unistd.h>

int check_double(char *str, char c, int pos)
{
	int i = 0;

	while (str[i] && i < pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int check_double2(char *str1, char *str2, char c, int pos)
{
	int i = 0;

	while (str1[i])
	{
		if (str1[i] == c)
			return (1);
		i++;
	}
	i = 0;
	while (str2[i] && i < pos)
	{
		if (str2[i] == c)
			return (1);
		i++;
	}
	return (0);
}


int main(int ac, char **av)
{
	int i = 0;

	char *str1 = av[1];
	char *str2 = av[2];

	if (ac == 3)
	{
		while (str1[i])
		{
			if (!check_double(str1, str1[i], i))
			{
				write(1, &str1[i], 1);
			}
			i++;
		}
		i = 0;
		while (str2[i])
		{
			if (!check_double2(str1, str2, str2[i], i))
			{
				write(1, &str2[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
