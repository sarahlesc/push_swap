#include "../include/push_swap.h"

int	swap_list_stack_a(t_double_list **stack_a, t_compt *compt)
{
	int				store;
	t_double_list	*temp;

	temp = *stack_a;
	if (stack_a == NULL || ft_double_lstsize(*stack_a) <= 1)
		return (-1);
	store = temp->content;
	temp->content = temp->next->content;
	temp->next->content = store;
	compt->value++;
	printf("sa\n");
	return (0);
}

int	swap_list_stack_b(t_double_list **stack_b, t_compt *compt)
{
	int				store;
	t_double_list	*temp;

	temp = *stack_b;
	if (stack_b == NULL || ft_double_lstsize(*stack_b) <= 1)
		return (-1);
	store = temp->content;
	temp->content = temp->next->content;
	temp->next->content = store;
	compt->value++;
	printf("sb\n");
	return (0);
}

void	swap_both(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	swap_list_stack_a(stack_a, compt);
	swap_list_stack_b(stack_b, compt);
	compt->value--;
	printf("ss\n");
}

int	push_list_to_stack_a(t_double_list **first_stack,
		t_double_list **second_stack, t_compt *compt)
{
	t_double_list	*temp;
	int				store;

	temp = *second_stack;
	store = temp->content;
	ft_double_lstadd_front(first_stack, ft_double_lstnew(store));
	ft_double_lstdelone(second_stack, 0);
	compt->value++;
	printf("pa\n");
	return (0);
}


int	push_list_to_stack_b(t_double_list **first_stack,
		t_double_list **second_stack, t_compt *compt)
{
	t_double_list	*temp;
	int				store;

	temp = *second_stack;
	store = temp->content;
	ft_double_lstadd_front(first_stack, ft_double_lstnew(store));
	ft_double_lstdelone(second_stack, 0);
	compt->value++;
	printf("pb\n");
	return (0);
}
