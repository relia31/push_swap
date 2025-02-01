#include "../../push_swap.h"
// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.Le premier élément devient le dernier.
// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.Le premier élément devient le dernier.
// rr : ra et rb en même temps.



void rotate(t_stack **list)
{
    if (!list || !*list || !(*list)->next)
        return;

    t_stack *first = *list;
    t_stack *last = *list;

    // Aller au dernier élément
    while (last->next)
        last = last->next;

    // Mettre le premier élément à la fin
    *list = first->next;
    (*list)->prev = NULL;
    last->next = first;
    first->prev = last;
    first->next = NULL;
}


void    ra(t_stack **a)
{
    rotate(a);
}

void    rb(t_stack **b)
{
    rotate(b);
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
}