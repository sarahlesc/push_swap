#include "../include/push_swap.h"

void	medium_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	int		nb;

	(void)stack_b;
	nb = smallest_number_list(stack_a);
	move_to_top(nb, stack_a, compt);
	nb = biggest_number_list(stack_a);
}

void	move_to_top(int nb, t_double_list **stack_a, t_compt *compt)
{
	int				i;
	t_double_list	*temp;

	i = 0;
	temp = ft_double_lstfirst(*stack_a);
	while (nb != temp->content)
	{
		i++;
		temp = temp->next;
	}
	temp = ft_double_lstfirst(*stack_a);
	if (nb < ft_double_lstsize(*stack_a) / 2)
	{
		while (i > 0)
		{
			rotate_list(stack_a, compt);
			printf("ra\n");
			i--;
		}
	}
	else
	{
		while (i < ft_double_lstsize(*stack_a))
		{
			reverse_rotate_list(stack_a, compt);
			printf("rra\n");
			i++;
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
