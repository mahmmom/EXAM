#include <unistd.h>
#include <stdio.h>

void    ft_putnbr(int   num)
{
    char c;

    if (num < 10)
    {
        c = num + '0';
        write(1, &c, 1);
    }
    else
    {
        ft_putnbr(num / 10);
        ft_putnbr(num % 10);
    }
}

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return (result);
}

int is_prime(int n)
{
    if (n <= 1)
        return 0;
    
    int i = 2;
    while (i <= n / 2)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    
    return 1;
}

void	ft_print(int n)
{
	int sum = 0;
	int i = 2;

	while (i <= n)
	{
		if (is_prime(i) == 1)
			sum += i;
		++i;
	}
    ft_putnbr(sum);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ft_print(ft_atoi(av[1]));
    }
    else
		ft_putnbr(0);
    write(1, "\n", 1);
}
