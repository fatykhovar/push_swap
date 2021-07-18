#include "push_swap.h"

static int	minmax(const char *str, int sg)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 9 && (ft_strncmp(str, "2147483648", 10) > 0 && sg == -1))
		return (0);
	if (i > 9 && (ft_strncmp(str, "2147483647", 10) > 0 && sg == 1))
		return (-1);
	return (1);
}

static int	help(const char *str, int i)
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

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sg;

	i = 0;
	res = 0;
	sg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' ||str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else
	{
		if (str[i] == '-')
		{
			sg = -1;
			i++;
		}
	}
	if (minmax((char *)(str + i), sg) != 1)
		return (minmax((char *)(str + i), sg));
	res = help(str, i);
	return (sg * res);
}
