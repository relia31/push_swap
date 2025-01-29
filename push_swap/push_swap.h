#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

// Prototypes des fonctions utilitaires
int		ft_atoi(char *str);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst, void (*del)(void *));
void	ft_lstdelone(t_stack *lst, void (*del)(void *));
t_stack	*ft_lstnew(void *content);
void    del(void *content);

#endif