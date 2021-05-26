#include "../include/push_swap.h"

void	medium_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*cpy;
	int				pivot;

	temp = *stack_a;
	cpy = ft_double_lstcopy(temp);
	compt->median = find_quartiles(2, cpy);
	compt->quartile_one = smallest_number_list(stack_a);
	compt->quartile_three = compt->median;
	compt->quartile_four = biggest_number_list(stack_a);
	move_to_stack_b(compt->median, stack_a, stack_b, compt);
	move_to_stack_b(compt->quartile_four, stack_a, stack_b, compt);
	temp = *stack_a;
	while (temp->content != compt->quartile_one)
		rotate_list_stack_a(stack_a, compt);
	ft_double_lstclear(&cpy, 0);
}

void 	move_to_stack_b(int median, t_double_list **stack_a,
		t_double_list **stack_b, t_compt *compt)
{
	t_double_list	*temp;
	int				min;

	temp = *stack_a;;
	if (median == compt->quartile_one)
		min = smallest_number_list;
	if (median == compt->median)
		min = compt->quartile_one;
	if (median == compt->quartile_three)
		min = compt->median;
	if (median == compt->quartile_three)
		min = compt->median;
	if (median == compt->quartile_four)
		min = compt->quartile_three;
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
