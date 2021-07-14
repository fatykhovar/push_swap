#include "push_swap.h"

void	ps_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ps_rotate(int *a, int n)
{
	int	i;
	int	t;

	i = 0;
	t = a[0];
	while (i < n - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = t;
}

void	ps_rev_rotate(int *a, int n)
{
	int	i;
	int	t;

	i = n - 1;
	t = a[n - 1];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = t;
}

void	ps_push_to_from(int *a, int *b, int *n_a, int *n_b)
{
	int	i;
	int	t;

	i = *n_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	(*n_a)++;
	a[i] = b[0];
	while (i < *n_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*n_b)--;
}
