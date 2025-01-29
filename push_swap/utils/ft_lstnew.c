#include "../push_swap.h"

t_stack	*ft_lstnew(void *content)
{
	t_stack	*new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->value = *(int *)content;
	new_elem->next = NULL;
	return (new_elem);
}
