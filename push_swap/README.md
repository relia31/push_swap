Push_swap
Description

push_swap est un projet de tri de nombres à l'aide de deux piles (stack). L'objectif est de trier une liste de nombres en utilisant un nombre limité d'opérations sur les piles, telles que push, swap et rotate. Ce projet vise à comprendre les bases des structures de données comme les piles (stacks) et à développer des algorithmes efficaces pour manipuler ces données.
Fonctionnalités

    Tri de nombres en utilisant des piles (stack a et stack b).
    Gestion des erreurs comme les doublons.
    Utilisation d'algorithmes de tri efficaces en fonction du nombre d'éléments.

Compilation

Pour compiler le projet, tu peux utiliser le Makefile fourni. Il suffit d'exécuter la commande suivante dans le terminal :

make

Cela générera un exécutable push_swap dans le répertoire courant.
Exécution

Une fois le projet compilé, tu peux exécuter push_swap en fournissant des arguments numériques dans la ligne de commande. Par exemple :

./push_swap 1 2 4 5

Cela exécutera le tri des nombres 1, 2, 4, 5 en utilisant les piles.
Structures de données

Le programme utilise une structure de données appelée t_stack qui représente une pile. Chaque élément de la pile contient une valeur et un pointeur vers l'élément suivant.

typedef struct s_stack {
    int value;               // Valeur du nœud
    struct s_stack *next;    // Pointeur vers l'élément suivant
} t_stack;

Fonctionnalités principales
ft_isdigit

Vérifie si un caractère est un chiffre.
is_valid_number

Vérifie si une chaîne de caractères représente un nombre valide (avec ou sans signe).
args_to_list

Prend les arguments de la ligne de commande et crée une liste chaînée à partir des valeurs. Chaque élément de la liste représente un nombre à trier.
check_doublon

Vérifie si des doublons existent dans la liste. Si des doublons sont trouvés, le programme affiche un message d'erreur et termine l'exécution.
ft_lstnew

Crée un nouvel élément de liste avec une valeur donnée. La fonction alloue de la mémoire pour un nouvel élément, initialise sa valeur et son pointeur next à NULL.
ft_lstadd_back

Ajoute un nouvel élément à la fin de la liste chaînée.
ft_lstclear

Libère toute la mémoire allouée pour la liste chaînée, en appelant ft_lstdelone pour chaque élément.
ft_lstdelone

Libère la mémoire d'un seul élément de la liste.
Notes

    La gestion des erreurs est essentielle, notamment pour vérifier la validité des entrées et s'assurer qu'il n'y a pas de doublons dans les nombres fournis.
    Le programme utilise des fonctions de manipulation de liste chaînée pour ajouter et supprimer des éléments.

À faire

    Implémenter un algorithme de tri plus efficace pour les grands ensembles de nombres.



    organisation :
    
    srcs/operations/ → Pour les fonctions d'opérations sur les piles
        swap.c → sa, sb, ss
        push.c → pa, pb
        rotate.c → ra, rb, rr
        reverse_rotate.c → rra, rrb, rrr

    srcs/sorting/ → Pour les algorithmes de tri
        small_sort.c → Tri des petites listes (ex : 3 ou 5 nombres)
        big_sort.c → Algorithme principal pour les grandes listes





        ____________________________________________________

note **a : quand on modifie une liste chaînée, on passe un pointeur sur pointeur pour bien garder la modification.