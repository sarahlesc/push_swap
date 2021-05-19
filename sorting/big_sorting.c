#include "../include/push_swap.h"

void	large_sorting(t_double_list **stack_a, t_double_list **stack_b)
{
	t_double_list	*temp;
	int				median;
	int				i;

	temp = *stack_a;
	i = 0;
	median = find_median(temp);
	while (i < ft_double_lstsize(*stack_a))
	{
		if (temp->content < median)
			push_list(stack_b, stack_a);
		else
			rotate_list(stack_a);
		i++;
	}

}

int		find_median(t_double_list *stack)
{
	int				i;
	int				first;
	int				last;
	int				median;
	t_double_list	*temp;

	i = 0;
	temp = ft_double_lstlast(stack);
	last = temp->content;
	temp = ft_double_lstfirst(stack);
	first = temp->content;
	median = ft_double_lstsize(stack) / 2;
	swap_sort(&temp);
	ft_double_print_list(temp);
	while (i < median)
	{
		temp = temp->next;
		i++;
	}
	printf("median = %i\n", temp->content);
	return (temp->content);
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
