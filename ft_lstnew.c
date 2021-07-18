#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->value = value;
	new->next = NULL;
	return (new);
}
