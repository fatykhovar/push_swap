#include "push_swap.h"

t_list	*ps_swap(t_list *head)
{
	t_list	*h;
	t_list	*h_next;

	if (!head || !head->next)
		return (head);
	h = head;
	h_next = head->next;
	h->next = h_next->next;
	h_next->next = h;
	return (h_next);
}

t_list	*ps_rotate(t_list *head)
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
	return (h_next);
}

t_list	*ps_rev_rotate(t_list *head)
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
	return (t_next);
}

void	ps_push_to_from(t_list **a, t_list **b)
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
}
