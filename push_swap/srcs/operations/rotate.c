#include "../../push_swap.h"
// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.Le premier élément devient le dernier.
// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.Le premier élément devient le dernier.
// rr : ra et rb en même temps.



void    rotate(t_stack *list)
{
    t_stack *current = list;

    while(current && current->prev != NULL)
    {
        list = current->prev;
        current->next;
    }
    
}