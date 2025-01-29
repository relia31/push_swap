// Fonction pour empiler un élément sur la pile
void push(s_stack **stack, int value)
{
    s_stack *new_node = ft_lstnew((void *)(intptr_t)value);
    ft_lstadd_front(stack, new_node);
}

// Fonction pour dépiler un élément de la pile
int pop(s_stack **stack)
{
    s_stack *temp = *stack;
    int value;

    if (!stack || !*stack)
        return (-1); // Pile vide

    value = temp->value;
    *stack = (*stack)->next;
    free(temp);
    return (value);
}
