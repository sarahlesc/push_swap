#include "../include/push_swap.h"

void	medium_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*cpy;
	int				a;

	temp = *stack_a;
	cpy = ft_double_lstcopy(temp);
	a = find_median(cpy);
	printf("stack_b avant =\n");
	ft_double_print_list(*stack_b);
	move_to_stack_b(a, stack_a, stack_b, compt);
	a = biggest_number_list(stack_a);
	move_to_stack_b(a, stack_a, stack_b, compt);
	a = smallest_number_list(stack_a);
	temp = *stack_a;
	while (temp->content != a)
		rotate_list(stack_a, compt);
	ft_double_lstclear(&cpy, 0);
}

void 	move_to_stack_b(int median, t_double_list **stack_a, t_double_list **stack_b, t_compt *compt)
{
	t_double_list	*temp;

	temp = *stack_a;;
	while (temp != NULL)
	{
		if (temp->content <= median)
		{
			if (temp->previous != NULL)
				move_to_top(temp->content, stack_a, compt);
			push_list(stack_b, stack_a, compt);
			temp = *stack_a;
			printf("pb\n");
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
			rotate_list(stack, compt);
			printf("ra\n");
			pos--;
		}
	}
	else
	{
		while (pos < ft_double_lstsize(*stack))
		{
			reverse_rotate_list(stack, compt);
			printf("rra\n");
			pos++;
		}
	}
}

int	smallest_number_list(t_double_list **stack_a)
{
	t_double_list	*temp;
	int				nb;

	temp = ft_double_lstfirst(*stack_a);
	nb = temp->content;
	while (temp->next != NULL)
	{
		if (nb > temp->next->content)
			nb = temp->next->content;
		temp = temp->next;
	}
	return (nb);
}

int	biggest_number_list(t_double_list **stack_a)
{
	t_double_list	*temp;
	int				nb;

	temp = ft_double_lstfirst(*stack_a);
	nb = temp->content;
	while (temp->next != NULL)
	{
		if (nb < temp->next->content)
			nb = temp->next->content;
		temp = temp->next;
	}
	return (nb);
}
