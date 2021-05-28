#include "../include/push_swap.h"

void	move_to_top_stack_a(int nb, t_double_list **stack, t_compt *compt,
		int pos)
{
	t_double_list	*temp;

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

void	move_to_top_stack_b(int nb, t_double_list **stack, t_compt *compt,
		int pos)
{
	t_double_list	*temp;

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
			rotate_list_stack_b(stack, compt);
			pos--;
		}
	}
	else
	{
		while (pos < ft_double_lstsize(*stack))
		{
			reverse_rotate_list_stack_b(stack, compt);
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
	if (smallest_to_use(smallest, biggest, stack_b) == 1)
	{
		move_to_top_stack_b(smallest, stack_b, compt, 0);
		push_list_to_stack_a(stack_a, stack_b, compt);
		rotate_list_stack_a(stack_a, compt);
	}
	else
	{
		move_to_top_stack_b(biggest, stack_b, compt, 0);
		push_list_to_stack_a(stack_a, stack_b, compt);
	}
}

int	compare_nb_operations(int i, int j, t_double_list **stack)
{
	int				a;
	t_double_list	*temp;

	a = i;
	temp = *stack;
	if (a > ft_double_lstsize(temp) - i)
		a = ft_double_lstsize(temp) - i;
	if (a <= j && (a <= ft_double_lstsize(temp) - j))
		return (1);
	else
		return (2);
}
