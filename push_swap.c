#include "push_swap.h"

t_list	*list_init(char *argv[], int n)
{
	int		i;
	int		j;
	int		*a_sorted;
	t_list	*head;
	t_list	*t;

	a_sorted = malloc (sizeof(int) * n);
	head = ft_lstnew(ft_atoi(argv[1]));
	t = head;
	a_sorted[0] = t->value;
	i = 2;
	while (i < n)
	{
		t->next = ft_lstnew(ft_atoi(argv[i]));
		t = t->next;
		a_sorted[i - 1] = t->value;
		i++;
	}
	quicksort(a_sorted, 0, n - 1);
	t = head;
	while (t)
	{
		j = 0;
		while (j < n)
		{
			if (t->value == a_sorted[j])
			{
				t->index = j;
				break ;
			}
			j++;
		}
		t = t->next;
	}
	return (head);
}

int	mid_search(t_list *a, int n)
{
	int	sum;

	sum = 0;
	while (a)
	{
		sum += a->index;
		a = a->next;
	}
	return (sum / n);
}

int	main(int argc, char *argv[])
{
	int		*a_sorted;
	t_list	*a;
	t_list	*b;
	t_cur	*cur;
	t_list	*t;

	a_sorted = malloc (sizeof(int) * (argc - 1));
	cur = malloc (sizeof(t_cur));
	a = list_init(argv, argc);
	cur->mid = mid_search(a, argc - 1);
	t = a;
	while (t)
	{
		if (t->index < cur->mid)
		{
			ps_push_to_from(&b, &a);
			write(1, "pb\n", 3);
		}
		t = t->next;
	}
	while (a)
	{
		printf("%i\n", a->index);
		a = a->next;
	}
	printf("_____\n");
	while (b)
	{
		printf("%i\n", b->index);
		b = b->next;
	}
}
