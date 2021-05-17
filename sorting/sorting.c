#include "push_swap.h"

void 	type_sorting(t_double_list **stack_a, t_double_list **stack_b)
{
	if (ft_double_lstsize(*stack_a) <= 10)
		small_sorting(*stack_a, *stack_b);
	if (ft_double_lstsize(*stack_a) > 10 && ft_double_lstsize(*stack_a) <= 100)
		medium_sorting(*stack_a, *stack_b);
	if (ft_double_lstsize(*stack_a) > 100 && ft_double_lstsize(*stack_a) <= 500)
		large_sorting(*stack_a, *stack_b);
	else
		print_error();
}

void 	very_small_sorting(t_double_list **stack_a)
{
	int		i;

	i = 0;
	if (ft_double_lstsize(*stack_a) < 4)
	{
		stack_a = ft_double_lstlast(*stack_a)
		if (stack_a->content < stack_a->previous->content)
			reverse_rotate_list(*stack_a);
		stack_a = ft_double_lstfirst(*stack_a)
		if (stack_a->content > stack_a->next->content)
			swap_list(*stack_a);
		if (stack_a->content > ft_double_lstlast(*stack_a)->content) // ça marche peut etre pas ça mais je veux aller à la fin de la liste 
			reverse_rotate_list(*stack_a);
	}
}

void 	small_sorting(t_double_list **stack_a, t_double_list **stack_b)
{
	if (ft_double_lstsize(*stack_a) < 4)
		very_small_sorting(*stack_a);
	if (ft_double_lstsize(*stack_a) > 3 && ft_double_lstsize(*stack_a) < 6)
	{
		while (ft_double_lstsize(*stack_a) != 3)
			push_list(*stack_a, *stack_b);
		very_small_sorting(*stack_a);
		very_small_sorting(*stack_b);
		while (ft_double_lstsize(*stack_b) != 0)
			push_list(*stack_b, *stack_a);
	}
}

void	stack_is_sorted(t_double_list **stack)
{
	int		i;

	i = 0;
	while (i < ft_double_lstsize(*stack))
	{
		if (stack->content >= stack->next->content)
		{
			printf("KO\n"); // faire une fonction pour bien sortir en free tout ?
			exit (0);
		}
		stack = stack->next;
		i++;
	}
	printf("OK");
}
