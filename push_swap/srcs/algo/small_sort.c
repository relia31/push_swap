#include "../../push_swap.h"
//Tri des petites listes (ex : 3 ou 5 nombres)


void small_sort(t_stack **a)
{
    if (is_sorted(*a))
        return ;
    if (stack_size(*a) == 2)
        sa(*a); // Correction ici
    else if (stack_size(*a) == 3)
    {
        if ((*a)->value > (*a)->next->value && (*a)->value > (*a)->next->next->value)
            ra(a); // Correction ici
        if ((*a)->value < (*a)->next->value && (*a)->next->value > (*a)->next->next->value)
            sa(*a); // Correction ici
        if ((*a)->value > (*a)->next->value && (*a)->next->value < (*a)->next->next->value)
            rra(a); // Correction ici
    }
}

