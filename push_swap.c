#include "push_swap.h"

t_list	*list_init(char *argv[], int n)
{
	int		i;
	int		j;
	int		*a_sorted;
	t_list	*head;
	t_list	*t;

	a_sorted = malloc(sizeof(int) * n);
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
				break;
			}
			j++;
		}
		t = t->next;
	}
	return (head);
}

void mid_search(t_cur **cur, t_list *a)
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
	if (n / 2 == 0)
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

void	max_to_a(t_cur *cur, t_list *a, t_list *b)
{
	int	i;

	i = 0;
	while (i < cur->mid_count)
	{
		if (b->index > cur->mid)
		{
			ps_push_to_from(&a, &b, 'a', &cur);
			i++;
		}
		else
			b = ps_rotate(b, 'b', &cur);
	}
}

// void	min_to_b(t_cur *cur, t_list *a, t_list *b)
// {
// 	int	i;

// 	if (elem_count(a) < 3)
// 		return ;
// 	min_to_b(cur, a, b);
// 	i = 0;
// 	while (i < cur->mid_count)
// 	{
// 		if (a->index < cur->mid)
// 		{
// 			ps_push_to_from(&b, &a, 'b', &cur);
// 			i++;
// 		}
// 		else
// 			a = ps_rotate(a, 'a', &cur);
// 	}
// }

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_cur	*cur;
	t_list	*t;
	t_list	*m;
	int		i;

	cur = malloc(sizeof(t_cur));
	a = list_init(argv, argc);
	if (duplicates(a))
		error_exit();
	t = a;
	while (t)
	{
		printf("%i\n", t->index);
		t = t->next;
	}
	printf("_____\n");
	while (if_sorted(a) == 0 && elem_count(a) == argc - 1)
	{
		while (if_sorted(a) == 0 && elem_count(a) > 2)
		{
			mid_search(&cur, a);
			//print
			t = a;
			m = b;
			printf("a   b\n");
			while (t || m)
			{
				if (t)
				{
					printf("%i", t->index);
					t = t->next;
				}
				printf("   ");
				if (m)
				{
					printf("%i", m->index);
					m = m->next;
				}
				printf("\n");
			}
			printf("mid: %i\n", cur->mid);
			printf("mid_count: %i\n", cur->mid_count);
			//print
			i = 0;
			while (i < cur->mid_count)
			{
				if (a->index < cur->mid)
				{
					ps_push_to_from(&b, &a, 'b', &cur);
					i++;
				}
				else
					a = ps_rotate(a, 'a', &cur);
			}
		}
		if (a->index > a->next->index)
			a = ps_swap(a, 'a', &cur);
		while (elem_count(b) > 2)
		{
			mid_search(&cur, b);
			//print
			t = a;
			m = b;
			while (t || m)
			{
				if (t)
				{
					printf("%i", t->index);
					t = t->next;
				}
				printf("   ");
				if (m)
				{
					printf("%i", m->index);
					m = m->next;
				}
				printf("\n");
			}
			printf("mid: %i\n", cur->mid);
			printf("mid_count: %i\n", cur->mid_count);
			//print
			i = 0;
			while (i < cur->mid_count)
			{
				if (b->index > cur->mid)
				{
					ps_push_to_from(&a, &b, 'a', &cur);
					i++;
				}
				else
					b = ps_rotate(b, 'b', &cur);
			}
		}
		if (b->index < b->next->index)
			b = ps_swap(b, 'b', &cur);
		ps_push_to_from(&a, &b, 'a', &cur);
		ps_push_to_from(&a, &b, 'a', &cur);
	}
	while (a)
	{
		printf("%i\n", a->value);
		a = a->next;
	}
	printf("_____\n");
	while (b)
	{
		printf("%i\n", b->value);
		b = b->next;
	}
	printf("oper: %i\n", cur->oper_count);
}
