#include "../include/push_swap.h"

void	large_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*cpy;
	int				median;
	int				quartile_one;
	int				quartile_three;

	temp = *stack_a;
	cpy = ft_double_lstcopy(temp);
	median = find_median(cpy);
	quartile_one = find_quartiles(1, cpy);
	quartile_three = find_quartiles(3, cpy);
	printf("quartile one = %i\n", quartile_one);
	printf("quartile three = %i\n", quartile_three);
	exit (0);
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
	push_all_to_stack_a(stack_a, stack_b, compt);
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
	while (i < median)
	{
		temp = temp->next;
		i++;
	}
	printf("median = %i\n", temp->content);
	return (temp->content);
}

int		find_quartiles(double q, t_double_list *stack)
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

void	push_all_to_stack_a(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	while (*stack_b != NULL)
	{
		push_list(stack_a, stack_b, compt);
		printf("pa\n");
	}
}
