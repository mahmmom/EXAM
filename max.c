#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    unsigned int i;
    int max;

    if (!tab)
        return (0);
    i = 1;
    max = tab[0];
    while (i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return (max);
}

/*int main (void)
{
    int tab[5] = {0,50000,3,20,10};
    
    printf("%d\n", max(tab, 5));
}*/
