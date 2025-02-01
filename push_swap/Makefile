NAME = push_swap

SRCS = main.c utils/ft_atoi.c utils/ft_lstadd_back.c utils/ft_lstclear.c utils/ft_lstdelone.c utils/ft_lstnew.c utils/ft_lstlast.c utils/ft_lstadd_front.c utils/sort_utils.c srcs/operations/swap.c srcs/operations/push.c srcs/operations/rotate.c srcs/operations/reverse_rotate.c srcs/algo/radix_sort.c srcs/algo/small_sort.c srcs/parsing.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I includes

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


all: $(NAME)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
