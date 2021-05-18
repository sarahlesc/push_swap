#include "../include/push_swap.h"

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
