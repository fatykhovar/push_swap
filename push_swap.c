#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	i;
	int	n_a;
	int	n_b;

	i = 0;
	n_a = argc - 1;
	n_b = 0;
	a = malloc (sizeof(int) * (argc - 1));
	b = malloc (sizeof(int) * (argc - 1));
	while (i < n_a)
	{
		a[i] = ft_atoi(argv[i + 1]);
		//printf("%i\n", a[i]);
		i++;
	}
	i = 0;
	while (i < n_a && a[i] < a[i + 1])
		i++;
	while (i < n_a)
	{
		ps_rev_rotate(a, n_a);
		write(1, "rra\n", 4);
		ps_push_to_from(b, a, &n_b, &n_a);
		write(1, "pb\n", 3);
		i++;
	}
	printf("n_a: %d, n_b: %d\n", n_a, n_b);
	printf("a        b\n");
	i = 0;
	while (i < n_a || i < n_b)
	{
		printf("%d       %d\n", a[i], b[i]);
		i++;
	}
}
