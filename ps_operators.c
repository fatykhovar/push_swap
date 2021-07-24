#include "push_swap.h"

t_list	*ps_swap(t_list *head, char c, t_cur **cur)
{
	t_list	*h;
	t_list	*h_next;

	if (!head || !head->next)
		return (head);
	h = head;
	h_next = head->next;
	h->next = h_next->next;
	h_next->next = h;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	(*cur)->oper_count++;
	return (h_next);
}

t_list	*ps_rotate(t_list *head, char c, t_cur **cur)
{
	t_list	*t;
	t_list	*h_next;

	if (!head || !head->next)
		return (head);
	h_next = head->next;
	t = head->next;
	while (t->next)
		t = t->next;
	t->next = head;
	head->next = 0;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	(*cur)->oper_count++;
	return (h_next);
}

t_list	*ps_rev_rotate(t_list *head, char c, t_cur **cur)
{
	t_list	*t;
	t_list	*t_next;

	t = head;
	if (!head || !head->next)
		return (head);
	while (t->next->next)
		t = t->next;
	t_next = t->next;
	t->next->next = head;
	t->next = 0;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
	(*cur)->oper_count++;
	return (t_next);
}

void	ps_push_to_from(t_list **a, t_list **b, char c, t_cur **cur)
{
	t_list	*b_next;
	t_list	*t_b;

	if (!b)
		return ;
	t_b = *b;
	b_next = (*b)->next;
	(*b)->next = *a;
	*a = t_b;
	*b = b_next;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	(*cur)->oper_count++;
}
