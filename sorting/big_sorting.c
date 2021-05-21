#include "../include/push_swap.h"

void	large_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
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
	temp = ft_double_lstfirst(temp);
	printf("stack_b =\n");
	ft_double_print_list(*stack_b);
	ft_double_lstclear(&cpy, 0);
	ft_double_lstclear(stack_b, 0);
}

int		find_median(t_double_list *stack)
{
	int				i;
	int				median;
	t_double_list	*temp;

	i = 0;
	temp = ft_double_lstfirst(stack);
	median = ft_double_lstsize(stack) / 2;
	swap_sort(&temp);
	//printf("temp = \n");
	//ft_double_print_list(temp);
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

/*void	quick_sort(t_double_list **stack)
{
	
}*/
