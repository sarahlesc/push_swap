#include "../include/push_swap.h"

void	medium_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*cpy;

	temp = *stack_a;
	cpy = ft_double_lstcopy(temp);
	compt->median = find_quartiles(2, cpy);
	compt->quartile_one = smallest_number_list(stack_a);
	compt->quartile_three = compt->median;
	compt->quartile_four = biggest_number_list(stack_a);
	move_stack_medium(compt->median, stack_a, stack_b, compt);
	move_stack_medium(compt->quartile_four, stack_a, stack_b, compt);
	temp = *stack_a;
	while (temp->content != compt->quartile_one)
		rotate_list_stack_a(stack_a, compt);
	ft_double_lstclear(&cpy, 0);
}

void 	move_stack_medium(int pivot, t_double_list **stack_a,
		t_double_list **stack_b, t_compt *compt)
{
	t_double_list	*temp;
	int				min;

	temp = *stack_a;
	if (pivot == compt->median)
		min = smallest_number_list(stack_a);
	else if (pivot == compt->quartile_four)
		min = compt->median;
	while (temp != NULL)
	{
		if (temp->content <= pivot && temp->content >= min)
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
