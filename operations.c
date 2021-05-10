#include "include/push_swap.h"

int		swap_list(t_list **stack)
{
	int i;
	t_list *temp;

	if (ft_lstsize(*stack) == 0 || ft_lstsize(*stack) == 1)
		return (-1);
	i = 0;
	while (temp != NULL)
	{
		temp->next = 
		i++;
		if (i == 2)
			break;
	}
	return (0);
}

void	swap_both(t_list **stack_a, t_liste **stak_b)
{
	swap_list(stack_a);
	swap_list(stack_b);
}

int		push_list(t_list **first_stack, t_list **second_stack)
{
	if (ft_lstsize(*second_stack) == 0)
		return (-1);
}

int		rotate_list(t_list **stack)
{
	if (ft_lstsize(*stack) == 0 || ft_lstsize(*stack) == 1)
		return (-1);
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate_list(stack_a);
	rotate_list(stack_b);
}

void	reverse_rotate_list(t_list **stack)
{
	if (ft_lstsize(*stack) == 0 || ft_lstsize(*stack) == 1)
		return (-1);
}


void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_list(stack_a);
	reverse_rotate_list(stack_b);
}
