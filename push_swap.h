#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

void	ps_swap(int *a, int *b);
void	ps_rotate(int *a, int n);
void	ps_rev_rotate(int *a, int n);
void	ps_push_to_from(int *a, int *b, int *n_a, int *n_b);

#endif