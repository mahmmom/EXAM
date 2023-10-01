#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

void	swap_values(t_list *a, t_list *b)
{
	int swap = a->data;
	a->data = b->data;
	b->data = swap;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swapped = 1;
	t_list *cur = lst;

	while (swapped == 1)
	{
		swapped = 0;
		while (cur != 0 && cur->next != 0)
		{
			if (cmp(cur->data, cur->next->data) == 0)
			{
				swap_values(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
		cur = lst;
	}
	return (lst);
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
