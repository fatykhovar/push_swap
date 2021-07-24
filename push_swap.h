#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}	t_list;
typedef struct s_cur
{
	int	mid;
	int	mid_count;
	int	oper_count;
}	t_cur;
t_list		*ps_swap(t_list *head, char c, t_cur **cur);
t_list		*ps_rotate(t_list *head, char c, t_cur **cur);
t_list		*ps_rev_rotate(t_list *head, char c, t_cur **cur);
void		ps_push_to_from(t_list **a, t_list **b, char c, t_cur **cur);
void		ft_swap(int *a, int *b);
void		quicksort(int *number, int first, int last);
static int	minmax(const char *str, int sg);
static int	help(const char *str, int i);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_list		*ft_lstnew(int value);
int			if_sorted(t_list *head);
void		mid_search(t_cur **cur, t_list *a);
int			elem_count(t_list *head);
int			duplicates(t_list *head);
void		error_exit(void);

#endif