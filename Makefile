SRCS =		ft_atoi.c ps_operators.c ft_lstnew.c ps_utils.c ft_strncmp.c push_swap.c
OBJS =		$(SRCS:.c=.o)
NAME =		libftpush_swap.a
HEADERS =   push_swap.h
INCLUDES =	./
GCC =		gcc
ARRC =		ar rc
RLIB =		ranlib
RM =		rm -f
CFLAGS =	-Wall -Wextra -Werror

.c.o:
			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(ARRC) $(NAME) $(OBJS)
			$(RLIB) $(NAME)

# push_swap:	a.out
# 			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)
			
fclean:		clean
			$(RM) $(NAME) 

re:			fclean all

.PHONY:		all clean clean fclean re