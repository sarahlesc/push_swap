#include "../include/push_swap.h"

void	call_push_swap(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	if (ft_double_lstsize(*stack_a) <= 10)
		small_sorting(stack_a, stack_b, compt);
	else if (ft_double_lstsize(*stack_a) > 10
		&& ft_double_lstsize(*stack_a) <= 100)
		large_sorting(stack_a, stack_b, compt);
	else if (ft_double_lstsize(*stack_a) > 100 &&
	ft_double_lstsize(*stack_a) <= 500)
		large_sorting(stack_a, stack_b, compt);
	else
		print_error(stack_a);
}

void	very_small_sorting(t_double_list **stack_a, t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*temp2;

	temp2 = ft_double_lstfirst(*stack_a);
	if (temp2->content > temp2->next->content)
	{
		swap_list(stack_a, compt);
		printf("sa\n");
	}
	temp = ft_double_lstlast(*stack_a);
	if (temp->content < temp->previous->content)
	{
		reverse_rotate_list(stack_a, compt);
		printf("rra\n");
	}
	temp2 = ft_double_lstfirst(*stack_a);
	if (temp2->content > temp->content)
	{
		reverse_rotate_list(stack_a, compt);
		printf("rra\n");
	}
	if (temp2->content > temp2->next->content)
	{
		swap_list(stack_a, compt);
		printf("sa\n");
	}
}

void	small_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	int				nb;

	if (ft_double_lstsize(*stack_a) < 4)
		very_small_sorting(stack_a, compt);
	else
	{
		while (ft_double_lstsize(*stack_a) != 3)
		{
			nb = smallest_number_list(stack_a);
			move_to_top(nb, stack_a, compt);
			push_list(stack_b, stack_a, compt);
			printf("pb\n");
		}
		very_small_sorting(stack_a, compt);
		while (ft_double_lstsize(*stack_b) > 0)
		{
			push_list(stack_a, stack_b, compt);
			printf("pa\n");
		}
	}
}

void	stack_is_sorted(t_double_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content >= stack->next->content)
		{
			printf("KO\n"); // faire une fonction pour bien sortir en free tout ?
			exit(0);
		}
		stack = stack->next;
	}
	printf("OK\n");
}
