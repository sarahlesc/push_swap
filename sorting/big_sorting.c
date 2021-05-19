#include "../include/push_swap.h"

void	large_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*temp2;
	int				median;

	temp = *stack_a;
	temp2 = malloc(sizeof(t_double_list) * ft_double_lstsize(temp));
	*temp2 = *temp;
//	printf("temp2_before = \n");
//	ft_double_print_list(temp2);
	median = find_median(temp2);
	printf("temp_hello = ");
	ft_double_print_list(temp);
	while (temp->next != NULL)
	{
		if (temp->content < median)
		{
			move_to_top(temp->content, &temp, compt);
			push_list(stack_b, stack_a, compt);
		}
		temp = temp->next;
	}
}

int		find_median(t_double_list *stack)
{
	int				i;
	int				first;
	int				last;
	int				median;
	t_double_list	*temp;

	printf("temp2_before = \n");
	ft_double_print_list(stack);
	i = 0;
	temp = ft_double_lstlast(stack);
	last = temp->content;
	temp = ft_double_lstfirst(stack);
	first = temp->content;
	median = ft_double_lstsize(stack) / 2;
	swap_sort(&temp);
	while (i < median)
	{
		temp = temp->next;
		i++;
	}
	printf("median = %i\n", temp->content);
	printf("temp2_after = \n");
	ft_double_print_list(stack);
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
