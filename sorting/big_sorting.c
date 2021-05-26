#include "../include/push_swap.h"

void	large_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*cpy;

	temp = *stack_a;
	cpy = ft_double_lstcopy(temp);
	compt->quartile_one = find_quartiles(1, cpy);
	compt->median = find_quartiles(2, cpy);
	compt->quartile_three = find_quartiles(3, cpy);
	compt->quartile_four = biggest_number_list(stack_a);
	move_to_stack_b(compt->quartile_one, stack_a, stack_b, compt);
	move_to_stack_b(compt->median, stack_a, stack_b, compt);
	move_to_stack_b(compt->quartile_three, stack_a, stack_b, compt);
	move_to_stack_b(compt->quartile_four, stack_a, stack_b, compt);
	temp = ft_double_lstfirst(temp);
	push_all_to_stack_a(stack_a, stack_b, compt);
	ft_double_lstclear(&cpy, 0);
}

void	sort_stack_b(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	int				smallest;
	int				biggest;

	smallest = smallest_number_list(stack_b);
	biggest = biggest_number_list(stack_b);
	if (smallest_or_biggest(smallest, biggest, stack_b) == 1)
	{
		move_to_top(smallest, stack_b, compt);
		push_list(stack_a, stack_b, compt);
		printf("pa\n");
		rotate_list(stack_a, compt);
	}
	else
	{
		move_to_top(biggest, stack_b, compt);
		push_list(stack_a, stack_b, compt);
		printf("pa\n");
	}
}

int		smallest_or_biggest(int smallest, int biggest, t_double_list **stack)
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
