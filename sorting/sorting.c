#include "../include/push_swap.h"

void 	call_push_swap(t_double_list **stack_a, t_double_list **stack_b)
{
	if (ft_double_lstsize(*stack_a) <= 10)
		small_sorting(stack_a, stack_b);
	//if (ft_double_lstsize(*stack_a) > 10 && ft_double_lstsize(*stack_a) <= 100)
	//	medium_sorting(stack_a, stack_b);
	//if (ft_double_lstsize(*stack_a) > 100 && ft_double_lstsize(*stack_a) <= 500)
	//	large_sorting(stack_a, stack_b);
	else
		print_error();
}

void 	very_small_sorting(t_double_list **stack_a)
{
	int			i;
	t_double_list	*temp;
	t_double_list	*temp2;

	i = 0;
	if (ft_double_lstsize(*stack_a) < 4)
	{
		temp = ft_double_lstlast(*stack_a);
		if (temp->content < temp->previous->content)
			reverse_rotate_list(stack_a);
		temp = ft_double_lstfirst(*stack_a);
		if (temp->content > temp->next->content)
			swap_list(stack_a);
		temp2 = ft_double_lstlast(*stack_a);
		if (temp->content > temp2->content) // ça marche peut etre pas ça mais je veux aller à la fin de la liste 
			reverse_rotate_list(stack_a);
	}
}

void 	small_sorting(t_double_list **stack_a, t_double_list **stack_b)
{
	if (ft_double_lstsize(*stack_a) < 4)
		very_small_sorting(stack_a);
	if (ft_double_lstsize(*stack_a) > 3 && ft_double_lstsize(*stack_a) < 6)
	{
		while (ft_double_lstsize(*stack_a) != 3)
			push_list(stack_a, stack_b);
		very_small_sorting(stack_a);
		very_small_sorting(stack_b);
		while (ft_double_lstsize(*stack_b) != 0)
			push_list(stack_b, stack_a);
	}
}

void	stack_is_sorted(t_double_list *stack)
{
	int		i;
	t_double_list	*temp;

	temp = stack;
	i = 0;
	while (i < ft_double_lstsize(stack))
	{
		if (temp->content >= temp->next->content)
		{
			printf("KO\n"); // faire une fonction pour bien sortir en free tout ?
			exit (0);
		}
		temp = temp->next;
		i++;
	}
	printf("OK");
}
