#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	quicksort(int *number, int first, int last)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{	
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
				ft_swap(&number[i], &number[j]);
		}
		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		quicksort(number, first, j - 1);
		quicksort(number, j + 1, last);
	}
}

int	if_sorted(t_list *head)
{
	while (head)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}


int	elem_count(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
