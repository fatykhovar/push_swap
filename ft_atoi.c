#include "push_swap.h"

int	minmax(const char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 9 && ft_strncmp(str, "2147483648", 10) > 0)
		return (1);
	return (0);
}

int	help(const char *str, int i)
{
	int	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	sg;

	i = 0;
	sg = 1;
	if (str[0] == '-')
	{
		sg = -1;
		i++;
	}
	j = i;
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			error_exit();
		j++;
	}
	if (minmax((char *)(str + i)) == 1)
		error_exit();
	return (sg * help(str, i));
}
