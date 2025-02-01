#include "push_swap.h"
#include <string.h>

// Fonction pour afficher les pile (utile pour le debug)
void print_stacks(t_stack *a, t_stack *b)
{
    printf("Pile A     | Pile B\n");
    printf("----------------------\n");

    while (a || b)
    {
        if (a)
        {
            printf("%-10d", a->value);
            a = a->next;
        }
        else
            printf("           "); // Espace si la pile A est vide

        printf("| ");

        if (b)
        {
            printf("%d\n", b->value);
            b = b->next;
        }
        else
            printf("\n"); // Nouvelle ligne si la pile B est vide
    }
}



// Vérifie si un caractère est un chiffre
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// Vérifie si une chaîne représente un nombre valide
int	is_valid_number(const char *str)
{
	if (str[0] == '+' || str[0] == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

//crée une liste chainée à partir des arguments
t_stack	*args_to_list(int argc, char **argv)
{
	t_stack	*head = NULL;
	t_stack	*new_node;
	int		i;
	int		num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]); // Convertir l'argument en entier
		//printf("Conversion de %s en %d\n", argv[i], num);
		if (!is_valid_number(argv[i])) // Vérifier si c'est un nombre valide
		{
			ft_lstclear(&head, del);  // Libérer toute la liste si erreur
			return (NULL);
		}
		new_node = ft_lstnew(&num);  // Passer l'adresse de num
		if (!new_node)
		{
			ft_lstclear(&head, del);  // Libérer toute la liste si erreur
			return (NULL);
		}
		ft_lstadd_back(&head, new_node); // Ajouter à la liste
		//printf("Ajout de %d à la liste\n", num);

		i++;
	}
	return (head);
}


//fonction pour check si doublon
// objectif comparer les éléments de la liste entre eux
int	check_doublon(t_stack *head)
{
	t_stack	*current;
	t_stack	*checker;

	current = head;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1); // Doublon trouvé
			checker = checker->next;
		}
		current = current->next;
	}
	return (0); // Pas de doublon
}

void sort_stack(t_stack **a, t_stack **b)
{
    if (stack_size(*a) == 2)
        sa(*a);  // Corrigé : on passe *a au lieu de a
    else if (stack_size(*a) == 3)
        small_sort(a);
    else
        radix_sort(a, b);
}



// int	main(int argc, char **argv)
// {
// 	// crée la liste à partir des arguments
// 	t_stack *a = args_to_list(argc, argv);
// 	t_stack *b = NULL;

// 	// Vérifie si des doublons dans la liste
// 	if (check_doublon(a))
// 	{
// 		write(2, "Error: Duplicate numbers\n", 25);
// 		ft_lstclear(&a, del);  // Libère liste si doublon
// 		return (1);
// 	}

// 	write(1, "Arguments valides\n", 18);

//     printf("Avant :\n");
//    	print_stacks(a, b);

//     // if (argc > 2)
//     // {
//     //    char *cmd = argv[argc - 1];

// 	// 	if (strcmp(cmd, "ra") == 0)
// 	// 		ra(&a);
// 	// 	else if (strcmp(cmd, "rb") == 0 && b != NULL)  // Vérifie si B existe
// 	// 		rb(&b);
// 	// 	else if (strcmp(cmd, "rra") == 0)
// 	// 		rra(&a);
// 	// 	else if (strcmp(cmd, "rrb") == 0 && b != NULL)
// 	// 		rrb(&b);
// 	// 	else
// 	// 		printf("Commande non reconnue.\n");
// 	// }

//     printf("Après :\n");
// 	//ra(&a);
// 	pb(&a, &b);
// 	rb(&b);
	
// 	rra(&a);
// 	print_stacks(a, b);

// 	// Libérer toute la liste après utilisation
// 	ft_lstclear(&a, del);
// 	ft_lstclear(&b, del);

// 	return (0);
// }


int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b = NULL;

	if (argc < 2)
		return (1);

	// Convertir les arguments en liste chaînée
	a = args_to_list(argc, argv);
	if (!a || check_doublon(a))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&a, del);
		return (1);
	}

	// Exécuter l'algorithme de tri
	sort_stack(&a, &b);

	// Libérer la mémoire
	ft_lstclear(&a, del);
	ft_lstclear(&b, del);
	return (0);
}
