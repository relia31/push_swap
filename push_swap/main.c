#include "push_swap.h"




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
		printf("Conversion de %s en %d\n", argv[i], num);
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
		printf("Ajout de %d à la liste\n", num);

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



int	main(int argc, char **argv)
{
	// On crée la liste à partir des arguments
	t_stack *list = args_to_list(argc, argv);

	// Vérifier si des doublons existent dans la liste
	if (check_doublon(list))
	{
		write(2, "Error: Duplicate numbers\n", 25);
		ft_lstclear(&list, del);  // Libère toute la liste si doublon
		return (1);
	}

	write(1, "Arguments valides\n", 18);

	// Libérer toute la liste après utilisation
	ft_lstclear(&list, del);

	return (0);
}
