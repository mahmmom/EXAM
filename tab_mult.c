#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int ft_atoi(char *str)
{
    int result = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

void    print_num(int num)
{
    int i;

    i = 1;
    while (i < 10)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(num);
        write(1, " = ", 3);
        ft_putnbr(i * num);
        write(1, "\n", 1);
        i++;
    }
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        int num = ft_atoi(av[1]);
        print_num(num);
    }
    else
        write (1, "\n", 1);

    return (0);
}
