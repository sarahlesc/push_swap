#include "include/push_swap.h"

int	swap_list(t_double_list **stack, t_compt *compt)
{
	int				store;
	t_double_list	*temp;

	temp = *stack;
	if (stack == NULL || ft_double_lstsize(*stack) <= 1)
		return (-1);
	store = temp->content;
	temp->content = temp->next->content;
	temp->next->content = store;
	compt->value++;
	return (0);
}

void	swap_both(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	swap_list(stack_a, compt);
	swap_list(stack_b, compt);
	compt->value--;
	printf("ss\n");
}

int	push_list(t_double_list **first_stack,
		t_double_list **second_stack, t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*new;
	int				store;

	temp = *second_stack;
	store = temp->content;
	new = ft_double_lstnew(store);
	ft_double_lstadd_front(first_stack, new);
	ft_double_lstdelone(second_stack, 0);
	compt->value++;
	return (0);
}
