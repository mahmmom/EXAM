#include <unistd.h>

void    ft_print(int count)
{
    char digit;

    if (count >= 10)
        ft_print(count / 10);

    digit = (count % 10) + '0';
    write(1, &digit, 1);
}

int main (int ac, char **av)
{
    (void)av;

    ft_print(ac - 1);
    write(1, "\n", 1);
 
}
