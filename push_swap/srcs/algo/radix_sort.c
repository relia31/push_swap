#include "../../push_swap.h"

//Algorithme principal pour les grandes listes



int get_max_value(t_stack *a)
{
    int max = a->value;
    while (a)
    {
        if (a->value > max)
            max = a->value;
        a = a->next;
    }
    return max;
}

void radix_sort(t_stack **a, t_stack **b)
{
    int max_value = get_max_value(*a);
    int bits = 0;
    while ((max_value >> bits) > 0)
        bits++;

    for (int i = 0; i < bits; i++)
    {
        for (t_stack *tmp = *a; tmp != NULL; tmp = tmp->next)
        {
            if (((tmp->value >> i) & 1) == 0)
                pb(a, b); // Déplacer l'élément de A à B
            else
                ra(a);   // Rotation de A
        }
        while (*b) // Ramener les éléments de B à A
            pa(a, b);
    }
}
