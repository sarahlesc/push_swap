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
	while (temp->next != NULL)
	{
		printf("temp->content_before_if %d\n", temp->content);
		if (temp->content < median)
		{
			temp = ft_double_lstfirst(temp);
			printf("temp->content1 %d\n", temp->content);
			move_to_top(temp->content, &temp, compt);
			printf("temp_after_move = \n");
			ft_double_print_list(temp);
			push_list(stack_b, &temp, compt);
			printf("pb\n");
			printf("temp_after_push = \n");
			ft_double_print_list(temp);
			printf("temp->content2 %d\n", temp->content);
		}
		else
			temp = temp->next;
	}
	temp = ft_double_lstfirst(temp);
			printf("stack_a_yo = \n");
			ft_double_print_list(temp);
			printf("stack_b_yo = \n");
			ft_double_print_list(*stack_b);

	ft_double_lstclear(&cpy, 0);
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
