#include "../push_swap.h"


int stack_size(t_stack *a)
{
    int count = 0;
    while (a)
    {
        count++;
        a = a->next;
    }
    return count;
}

int is_sorted(t_stack *a)
{
    while (a && a->next)
    {
        if (a->value > a->next->value)
            return 0;
        a = a->next;
    }
    return 1;
}
