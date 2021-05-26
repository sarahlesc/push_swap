#include "../include/push_swap.h"

void	move_to_top(int nb, t_double_list **stack, t_compt *compt)
{
	int				pos;
	t_double_list	*temp;

	pos = 0;
	temp = *stack;
	while (nb != temp->content)
	{
		pos++;
		temp = temp->next;
	}
	temp = ft_double_lstfirst(*stack);
	if (pos < ft_double_lstsize(*stack) / 2)
	{
		while (pos > 0)
		{
			rotate_list_stack_a(stack, compt);
			pos--;
		}
	}
	else
	{
		while (pos < ft_double_lstsize(*stack))
		{
			reverse_rotate_list_stack_a(stack, compt);
			pos++;
		}
	}
}

void	swap_sort(t_double_list **stack)
{
	int				store;
	t_double_list	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
		{
			store = temp->content;
			temp->content = temp->next->content;
			temp->next->content = store;
			temp = ft_double_lstfirst(temp);
			swap_sort(&temp);
		}
		temp = temp->next;
	}
}

void	sort_stack_b(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	int				smallest;
	int				biggest;

	smallest = smallest_number_list(stack_b);
	biggest = biggest_number_list(stack_b);
	if (smallest_or_biggest(smallest, biggest, stack_b) == 1)
	{
		move_to_top(smallest, stack_b, compt);
		push_list_to_stack_a(stack_a, stack_b, compt);
		rotate_list_stack_a(stack_a, compt);
	}
	else
	{
		move_to_top(biggest, stack_b, compt);
		push_list_to_stack_a(stack_a, stack_b, compt);
	}
}

void	push_all_to_stack_a(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	while (*stack_b != NULL)
		push_list_to_stack_a(stack_a, stack_b, compt);
}
