#include "include/push_swap.h"

int		rotate_list(t_double_list **stack)
{
	t_double_list *temp1;
	t_double_list *temp2;

	if (ft_double_lstsize(*stack) == 0 || ft_double_lstsize(*stack) == 1)
		return (-1);
	temp1 = *stack;
	temp2 = ft_double_lstnew(temp1->content);
	temp1 = ft_double_lstlast(*stack);
	while (temp1->previous != NULL)
	{
		ft_double_lstadd_front(&temp2, ft_double_lstnew(temp1->content));
		temp1 = temp1->previous;
	}
	*stack = temp2;
	return (0);
}

void	rotate_both(t_double_list **stack_a, t_double_list **stack_b)
{
	rotate_list(stack_a);
	rotate_list(stack_b);
}

int		reverse_rotate_list(t_double_list **stack)
{
	t_double_list *temp1;
	t_double_list *temp2;

	if (ft_double_lstsize(*stack) == 0 || ft_double_lstsize(*stack) == 1)
		return (-1);
	temp1 = ft_double_lstlast(*stack);
	temp2 = ft_double_lstnew(temp1->content);
	temp1 = *stack;
	while (temp1->next != NULL)
	{
		ft_double_lstadd_back(&temp2, ft_double_lstnew(temp1->content));
		temp1 = temp1->next;
	}
	*stack = temp2;
	return (0);
}

void	reverse_rotate_both(t_double_list **stack_a, t_double_list **stack_b)
{
	reverse_rotate_list(stack_a);
	reverse_rotate_list(stack_b);}
