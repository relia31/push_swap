#include "../../push_swap.h"
// pa (push a) : Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
// pb (push b) : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.


// pa push(b, a);
// pb push(a, b);
void    push(t_stack **src, t_stack **dest)
{
    if (!src || !*src) // Vérifie si src est vide
        return;

    t_stack *top = *src;   // Récupère le premier élément
    *src = (*src)->next;   // Avance src vers l'élément suivant

    top->next = *dest;     // Place l'élément retiré au début de dest
    *dest = top;
}
