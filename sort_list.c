#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

void ft_swap(int *a, int *b) // swap funtion used to swap the data of c and d.
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *begin = lst; // pointer used to point head of the list.
	t_list *future; // pointer used for seconding while loop which will make the bubble (largest element) at the last of the list.
	while(lst)
	{
		future = lst->next;
		while (future)
		{
			if (!cmp(lst->data, future->data))
				ft_swap(&lst->data, &future->data);
			future = future->next;
		}
		lst = lst->next;
	}
	return (begin);
}

int		ascending(int a, int b)
{
		return (a <= b);
}

int	main(void)
{
	t_list *list;

	list = NULL;
	list = add_int(list, 9);
	list = add_int(list, 3);
	list = add_int(list, 2);
	list = add_int(list, 2);
	list = add_int(list, 1);
	list = sort_list(list, &ascending);

	while(list != NULL)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
	
	return (0);
}
