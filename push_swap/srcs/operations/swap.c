#include "../../push_swap.h"
// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
// ss : sa et sb en même temps.

//swap sa et sb 
//sa = swap(a);
//sb = swap(b);
void    swap(t_stack *list)
{
    t_stack  *current = list;
    int num;

    num = 0;
    //check si la liste a plus de 2 éléments
    while(current)
    {
        num++;
        current = current->next;
    }

    if(num >= 2)
    {
        int tmp = list->value;
        list->value = list->next->value;
        list->next->value = tmp;
    }
}

//ss
void    ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
}