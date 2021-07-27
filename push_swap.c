#include "push_swap.h"

void print(t_list *a, t_list *b, t_cur *cur)
{
	t_list *t;
	t_list *m;

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
	//printf("mid: %d\n", cur->mid);
}

t_list *list_init(char *argv[], int n)
{
	int i;
	int j;
	int *a_sorted;
	t_list *head;
	t_list *t;

	a_sorted = malloc(sizeof(int) * n);
	head = ft_lstnew(ft_atoi(argv[1]));
	t = head;
	a_sorted[0] = t->value;
	i = 1;
	while (i < n)
	{
		t->next = ft_lstnew(ft_atoi(argv[i + 1]));
		t->chunk_nb = -1;
		t->chunk_count = -1;
		t = t->next;
		a_sorted[i] = t->value;
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

void mid_search(t_cur **cur, t_list *a, int n)
{
	int sum;
	t_list *t;
	int i;

	sum = 0;
	i = 0;
	t = a;
	if (!cur || !a)
		return ;
	while (i < n)
	{
		sum += t->index;
		i++;
		t = t->next;
	}
	(*cur)->mid = sum / n;
	if (n % 2 == 0 && n > 1)
		(*cur)->mid++;
	t = a;
	i = 0;
	(*cur)->mid_count = 0;
	while (i < n)
	{
		if (t->index < (*cur)->mid)
			(*cur)->mid_count++;
		t = t->next;
		i++;
	}
}

void max_to_a(t_cur **cur, t_list **a, t_list **b, int n)
{
	int i;
	int j;
	int rotate_nb;
	int cur_chunk;

	if (n == 0 || !(*b))
		return ;
	max_to_a(cur, a, b, n / 2);
	cur_chunk = (*b)->chunk_nb;
	i = 0;
	while ((*b)->chunk_nb == cur_chunk && elem_count(*b) > 2)
	{
		mid_search(cur, *b, (*b)->chunk_count);
		printf("b: %d\n", (*b)->index);
		printf("mid: %d\n", (*cur)->mid);
		printf("mid_count: %d\n", (*cur)->mid_count);
		printf("chunk: %d\n", cur_chunk);
		printf("chunk_count: %d\n", (*b)->chunk_count);
		printf("n: %d\n", n);
		print(*a, *b, *cur);
		i = 0;
		rotate_nb = 0;
		while (i < (*cur)->mid_count + 1 && elem_count(*b) > 2)
		{
			if ((*b)->index >= (*cur)->mid)
			{
				ps_push_to_from(a, b, 'a', cur);
				i++;
			}
			else
			{
				//return ;
				(*b) = ps_rotate(*b, 'b', cur);
				rotate_nb++;
			}
		}
		j = 0;
		while (j < rotate_nb)
		{
			(*b) = ps_rev_rotate(*b, 'b', cur);
			j++;
		}
		i = 0;
		rotate_nb = 0;
		while ((*a)->next->next->chunk_nb == cur_chunk)
		{
			mid_search(cur, *a, (*cur)->mid_count + 1);
			while (i < (*cur)->mid_count)
			{
				if ((*a)->index < (*cur)->mid)
				{
					ps_push_to_from(b , a, 'b', cur);
					i++;
				}
				else
				{
					(*a) = ps_rotate(*a, 'a', cur);
					rotate_nb++;
				}
			}
			j = 0;
			while (j < rotate_nb)
			{
				(*a) = ps_rev_rotate(*a, 'b', cur);
				j++;
			}
		}
		if ((*a) && (*a)->next && (*a)->index > (*a)->next->index)
			(*a) = ps_swap((*a), 'a', cur);
	}
}

int main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;
	t_cur *cur;
	t_list *t;
	int i;
	int chunk;

	chunk = 0;
	cur = malloc(sizeof(t_cur));
	a = list_init(argv, argc - 1);
	if (duplicates(a) || argc < 2)
		error_exit();
	while (elem_count(a) > 2)
	{
		mid_search(&cur, a, elem_count(a));
		print(a, b, cur);
		i = 0;
		while (i < cur->mid_count)
		{
			if (a->index < cur->mid)
			{
				a->chunk_nb = chunk;
				a->chunk_count = cur->mid_count;
				ps_push_to_from(&b, &a, 'b', &cur);
				i++;
			}
			else
				a = ps_rotate(a, 'a', &cur);
		}
		chunk++;
	}
	if (a && a->next && a->index > a->next->index)
		a = ps_swap(a, 'a', &cur);
	mid_search(&cur, b, elem_count(b));
	print(a, b, cur);
	max_to_a(&cur, &a, &b, elem_count(b));
	printf("finished\n");
	if (b && b->next && b->index < b->next->index)
		b = ps_swap(b, 'b', &cur);
	while (b)
		ps_push_to_from(&a, &b, 'a', &cur);
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
