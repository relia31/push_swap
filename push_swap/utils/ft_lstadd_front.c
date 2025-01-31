#include "../push_swap.h"
//Ajoute l’élément ’new’ au début de la liste

void	ft_lstadd_front(t_stack**lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}