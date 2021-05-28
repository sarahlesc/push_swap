#include "../include/push_swap.h"

void	call_push_swap(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	if (ft_double_lstsize(*stack_a) <= 10)
		small_sorting(stack_a, stack_b, compt);
	else if (ft_double_lstsize(*stack_a) > 10
		&& ft_double_lstsize(*stack_a) <= 100)
		medium_sorting(stack_a, stack_b, compt);
	else if (ft_double_lstsize(*stack_a) > 100
		&& ft_double_lstsize(*stack_a) <= 500)
		large_sorting(stack_a, stack_b, compt);
	else
		print_error(stack_a);
}

int	stack_is_sorted(t_double_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content >= stack->next->content)
			return (-1);
		stack = stack->next;
	}
	return (0);
}
