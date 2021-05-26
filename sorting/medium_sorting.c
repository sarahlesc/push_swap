#include "../include/push_swap.h"

void	medium_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*cpy;
	int				pivot;

	temp = *stack_a;
	cpy = ft_double_lstcopy(temp);
	pivot = find_quartiles(2, cpy);
	move_to_stack_b(pivot, stack_a, stack_b, compt);
	move_to_stack_a(pivot, stack_a, stack_b, compt);
	pivot = smallest_number_list(stack_a);
	temp = *stack_a;
	while (temp->content != pivot)
		rotate_list_stack_a(stack_a, compt);
	ft_double_lstclear(&cpy, 0);
}

void 	move_to_stack_b(int median, t_double_list **stack_a,
		t_double_list **stack_b, t_compt *compt)
{
	t_double_list	*temp;

	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->content <= median)
		{
			if (temp->previous != NULL)
				move_to_top(temp->content, stack_a, compt);
			push_list_to_stack_b(stack_b, stack_a, compt);
			temp = *stack_a;
		}
		else
			temp = temp->next;
	}
	while (ft_double_lstsize(*stack_b) > 0)
		sort_stack_b(stack_a, stack_b, compt);
}

void 	move_to_stack_a(int median, t_double_list **stack_a,
		t_double_list **stack_b, t_compt *compt)
{
	t_double_list	*temp;

	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->content > median)
		{
			if (temp->previous != NULL)
				move_to_top(temp->content, stack_a, compt);
			push_list_to_stack_b(stack_b, stack_a, compt);
			temp = *stack_a;
		}
		else
			temp = temp->next;
	}
	while (ft_double_lstsize(*stack_b) > 0)
	{
		sort_stack_b(stack_a, stack_b, compt);
		printf("stack_b apres =\n");
		ft_double_print_list(*stack_b);
	}
}
