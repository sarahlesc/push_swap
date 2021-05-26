#include "../include/push_swap.h"

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

int	find_quartiles(double q, t_double_list *stack)
{
	int				i;
	double			quartile;
	t_double_list	*temp;

	i = 0;
	temp = ft_double_lstfirst(stack);
	quartile = ft_double_lstsize(stack) * (q / 4);
	swap_sort(&temp);
	while (i < quartile)
	{
		temp = temp->next;
		i++;
	}
	printf("quartile = %i\n", temp->content);
	return (temp->content);
}

int	smallest_or_biggest(int smallest, int biggest, t_double_list **stack)
{
	int				i;
	int				j;
	int				a;
	t_double_list	*temp;

	temp = *stack;
	i = 0;
	j = 0;
	while (temp->content != smallest)
	{
		temp = temp->next;
		i++;
	}
	temp = ft_double_lstfirst(temp);
	while (temp->content != biggest)
	{
		temp = temp->next;
		j++;
	}
	temp = ft_double_lstfirst(temp);
	a = i;
	if (a > ft_double_lstsize(temp) - i)
		a = ft_double_lstsize(temp) - i;
	if (a <= j && (a <= ft_double_lstsize(temp) - j))
		return (1);
	else
		return (2);
}
