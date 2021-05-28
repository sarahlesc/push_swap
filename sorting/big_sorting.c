#include "../include/push_swap.h"

void	large_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*cpy;

	temp = *stack_a;
	cpy = ft_double_lstcopy(temp);
	compt->chunk_one = divide_stack_by_eight(1, cpy);
	compt->chunk_two = divide_stack_by_eight(2, cpy);
	compt->chunk_three = divide_stack_by_eight(3, cpy);
	compt->chunk_four = divide_stack_by_eight(4, cpy);
	compt->chunk_five = divide_stack_by_eight(5, cpy);
	compt->chunk_six = divide_stack_by_eight(6, cpy);
	compt->chunk_seven = divide_stack_by_eight(7, cpy);
	compt->chunk_eight = biggest_number_list(stack_a);
	move_stack_large(compt->chunk_eight, stack_a, stack_b, compt);
	move_stack_large(compt->chunk_seven, stack_a, stack_b, compt);
	move_stack_large(compt->chunk_six, stack_a, stack_b, compt);
	move_stack_large(compt->chunk_five, stack_a, stack_b, compt);
	move_stack_large(compt->chunk_four, stack_a, stack_b, compt);
	move_stack_large(compt->chunk_three, stack_a, stack_b, compt);
	move_stack_large(compt->chunk_two, stack_a, stack_b, compt);
	move_stack_large(compt->chunk_one, stack_a, stack_b, compt);
	temp = *stack_a;
	while (temp->content != smallest_number_list(stack_a))
		reverse_rotate_list_stack_a(stack_a, compt);
	ft_double_lstclear(&cpy, 0);
}

void	move_stack_large(int pivot, t_double_list **stack_a,
		t_double_list **stack_b, t_compt *compt)
{
	t_double_list	*temp;
	int				min;

	temp = *stack_a;
	min = get_minimum(pivot, stack_a, compt);
	while (temp != NULL)
	{
		if (temp->content <= pivot && temp->content >= min)
		{
			if (temp->previous != NULL)
				move_to_top(temp->content, stack_a, compt, 0);
			push_list_to_stack_b(stack_b, stack_a, compt);
			temp = *stack_a;
		}
		else
			temp = temp->next;
	}
	while (ft_double_lstsize(*stack_b) > 0)
		sort_stack_b(stack_a, stack_b, compt);
}

int	get_minimum(int pivot, t_double_list **stack_a, t_compt *compt)
{
	int				min;

	min = 0;
	if (pivot == compt->chunk_one)
		min = smallest_number_list(stack_a);
	else if (pivot == compt->chunk_two)
		min = compt->chunk_one;
	else if (pivot == compt->chunk_three)
		min = compt->chunk_two;
	else if (pivot == compt->chunk_four)
		min = compt->chunk_three;
	else if (pivot == compt->chunk_five)
		min = compt->chunk_four;
	else if (pivot == compt->chunk_six)
		min = compt->chunk_five;
	else if (pivot == compt->chunk_seven)
		min = compt->chunk_six;
	else if (pivot == compt->chunk_eight)
		min = compt->chunk_seven;
	return (min);
}
