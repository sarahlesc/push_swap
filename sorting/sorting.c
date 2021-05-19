#include "../include/push_swap.h"

void	call_push_swap(t_double_list **stack_a, t_double_list **stack_b)
{
	if (ft_double_lstsize(*stack_a) <= 10)
		small_sorting(stack_a, stack_b);
	else if (ft_double_lstsize(*stack_a) > 10
		&& ft_double_lstsize(*stack_a) <= 100)
		medium_sorting(stack_a, stack_b);
	else if (ft_double_lstsize(*stack_a) > 100 &&
	ft_double_lstsize(*stack_a) <= 500)
		large_sorting(stack_a, stack_b);
	else
		print_error();
}

void	very_small_sorting(t_double_list **stack_a)
{
	t_double_list	*temp;
	t_double_list	*temp2;

	temp2 = ft_double_lstfirst(*stack_a);
	if (temp2->content > temp2->next->content)
	{
		swap_list(stack_a);
		printf("sa\n");
	}
	temp = ft_double_lstlast(*stack_a);
	if (temp->content < temp->previous->content)
	{
		reverse_rotate_list(stack_a);
		printf("rra\n");
	}
	temp2 = ft_double_lstfirst(*stack_a);
	if (temp2->content > temp->content)
	{
		reverse_rotate_list(stack_a);
		printf("rra\n");
	}
	if (temp2->content > temp2->next->content)
	{
		swap_list(stack_a);
		printf("sa\n");
	}
}

void	small_sorting(t_double_list **stack_a, t_double_list **stack_b)
{
	t_double_list	*temp;
	int				nb;

	if (ft_double_lstsize(*stack_a) < 4)
		very_small_sorting(stack_a);
	else
	{
		while (ft_double_lstsize(*stack_a) != 3)
		{
			nb = smallest_number_list(stack_a);
			move_to_top(nb, stack_a);
			push_list(stack_b, stack_a);
			printf("pb\n");
		}
		very_small_sorting(stack_a);
		if (ft_double_lstsize(*stack_b) > 1)
			temp = ft_double_lstfirst(*stack_b);
		while (ft_double_lstsize(*stack_b) > 0)
		{
			push_list(stack_a, stack_b);
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
