#include "../include/push_swap.h"

int		find_median(t_double_list **stack)
{
	int				i;
	int				first;
	int				last;
	int				median;
	t_double_list	*temp;

	i = 0;
	temp = ft_double_lstlast(*stack);
	last = temp->content;
	temp = ft_double_lstfirst(*stack);
	first = temp->content;
	median = ft_double_lstsize(*stack) / 2;
	printf("first = %d\n", first);
	printf("last = %d\n", last);
	ft_quick_sort(stack, first, last);
	while (i < median)
	{
		temp = temp->next;
		i++;
	}
	printf("median = %i\n", temp->content);
	return (temp->content);
}

void	ft_quick_sort(t_double_list **stack, int first, int last)
{
	int		i;
	int		j;
	int		t;
	int		pivot;
	t_double_list	*temp;
	t_double_list	*temp2;

	printf("coucou");
	i = 0;
	j = 0;
	temp = *stack;
	temp2 = *stack;
	while (temp->content != first)
		temp = temp->next; // on est sur le premier qu'on souhaite
	pivot = temp->content;
	while (temp->content != last)
		temp2 = temp2->next;
	if (first < last)
	{
		i = first;
		j = last;
		while (i < j)
		{
			while ((temp->content <= pivot) && (i < last))
			{
				i++;
				temp = temp->next;
			}
			while (temp2->content > pivot)
			{
				j--;
				temp2 = temp2->next;
			}
			if (i < j)
			{
				t = temp->content;
				temp->content = temp2->content;
				temp2->content = t;
			}
		}
		t = pivot;
		pivot = temp2->content;
		temp2->content = t;
		ft_quick_sort(&temp, first , j - 1);
		ft_quick_sort(&temp, j + 1, last);
	}
}
