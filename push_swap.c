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
				t->index = j + 1;
				break ;
			}
			j++;
		}
		t = t->next;
	}
	return (head);
}

void	mid_search(t_cur **cur, t_list *a)
{
	int		sum;
	int		n;
	t_list	*t;

	sum = 0;
	n = 0;
	t = a;
	while (t)
	{
		sum += t->index;
		n++;
		t = t->next;
	}
	(*cur)->mid = sum / n;
	if (n / 2)
		(*cur)->mid++;
	t = a;
	(*cur)->mid_count = 0;
	while (t)
	{
		if (t->index < (*cur)->mid)
			(*cur)->mid_count++;
		t = t->next;
	}
}

int	main(int argc, char *argv[])
{
	int		*a_sorted;
	t_list	*a;
	t_list	*b;
	t_cur	*cur;
	t_list	*t;
	int		i;

	a_sorted = malloc (sizeof(int) * (argc - 1));
	cur = malloc (sizeof(t_cur));
	a = list_init(argv, argc);
	t = a;
	while (t)
	{
		printf("%i\n", t->index);
		t = t->next;
	}
	printf("_____\n");
	while (!if_sorted(a))
	{
		while (elem_count(a) > 2)
		{
			mid_search(&cur, a);
			t = a;
			while (t)
			{
				printf("%i\n", t->index);
				t = t->next;
			}
			printf("mid: %i\n", cur->mid);
			printf("mid_count: %i\n", cur->mid_count);
			i = 0;
			while (i < cur->mid_count)
			{
				if (a->index < cur->mid)
				{
					ps_push_to_from(&b, &a, 'b');
					i++;
				}
				else
					a = ps_rotate(a, 'a');
			}
		}
		if (a->index > a->next->index)
			a = ps_swap(a, 'a');
		// mid_search(&cur, b, argc - 1);
		// i = 0;
		// while (i < cur->mid)
		// {
		// 	if (b->index > cur->mid)
		// 	{
		// 		ps_push_to_from(&a, &b, 'a');
		// 		i++;
		// 	}
		// 	else
		// 		b = ps_rotate(b, 'b');
		// }
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
