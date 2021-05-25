#include "../include/push_swap.h"

void	medium_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
{
	t_double_list	*temp;
	t_double_list	*cpy;
	int				median;

	temp = *stack_a;
	cpy = ft_double_lstcopy(temp);
	median = find_median(cpy);
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
	printf("stack_b =\n");
	ft_double_print_list(*stack_b);
	printf("stack_a =\n");
	ft_double_print_list(*stack_a);
	push_all_to_stack_a(stack_a, stack_b, compt);
	ft_double_lstclear(&cpy, 0);
}
}

void	move_to_top(int nb, t_double_list **stack_a, t_compt *compt)
{
	int				pos;
	t_double_list	*temp;

	pos = 0;
	temp = *stack_a;
	while (nb != temp->content)
	{
		pos++;
		temp = temp->next;
	}
	temp = ft_double_lstfirst(*stack_a);
	while (pos < ft_double_lstsize(*stack_a))
	{
		reverse_rotate_list(stack_a, compt);
		printf("rra\n");
		pos++;
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
