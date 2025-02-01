#include "../../push_swap.h"

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
// rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
// rrr : rra et rrb en même temps.


void reverse_rotate(t_stack **stack)
{
    if (!stack || !*stack || !(*stack)->next)
        return; // Rien à faire si la liste est vide ou a un seul élément

    t_stack *prev = NULL;
    t_stack *last = *stack;

    while (last->next)  // Trouver le dernier élément
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;  // L'avant-dernier devient le dernier
    last->next = *stack; // L'ancien dernier devient la nouvelle tête
    *stack = last;  // Mise à jour de la tête
}

void    rra(t_stack **a)
{
    reverse_rotate(a);
}

void    rrb(t_stack **b)
{
    reverse_rotate(b);
}

void    rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}
