#include "include/push_swap.h"

int		swap_list(t_double_list **stack)
{
	int				store;
	t_double_list	*temp;

	temp = *stack;
	if (stack == NULL || ft_double_lstsize(*stack) <= 1)
		return (-1);
	store = temp->content;
	temp->content = temp->next->content;
	temp->next->content = store;
	return (0);
}

void	swap_both(t_double_list **stack_a, t_double_list **stack_b)
{
	swap_list(stack_a);
	swap_list(stack_b);
}

int		push_list(t_double_list **first_stack,
		t_double_list **second_stack)
{
	t_double_list	*temp1;
	t_double_list	*temp2;
	int				store;

	temp1 = *first_stack;
	temp2 = *second_stack;
	store = temp2->content;
	ft_double_lstadd_front(first_stack, ft_double_lstnew(store));
	ft_double_lstdelone(second_stack, 0);
	return (0);
}
