#include "../push_swap.h"


void	del(void *content)
{
	(void)content;
} 

void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	free(lst);
}
