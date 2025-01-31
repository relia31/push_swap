#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

// Prototypes des fonctions utilitaires
int		ft_atoi(char *str);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst, void (*del)(void *));
void	ft_lstdelone(t_stack *lst, void (*del)(void *));
void	ft_lstadd_front(t_stack**lst, t_stack *new);
t_stack	*ft_lstnew(void *content);
t_stack	*ft_lstlast(t_stack *lst);
void    del(void *content);


//push swap fonctions
void    swap(t_stack *a);
void    ss(t_stack *a, t_stack *b);
void    push(t_stack **src, t_stack **dest);

#endif