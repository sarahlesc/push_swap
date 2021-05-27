#include "../include/push_swap.h"

void	call_push_swap(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	if (ft_double_lstsize(*stack_a) <= 10)
		small_sorting(stack_a, stack_b, compt);
	else if (ft_double_lstsize(*stack_a) > 10
		&& ft_double_lstsize(*stack_a) <= 100)
		medium_sorting(stack_a, stack_b, compt);
	else if (ft_double_lstsize(*stack_a) > 100 &&
	ft_double_lstsize(*stack_a) <= 500)
		large_sorting(stack_a, stack_b, compt);
	else
		print_error(stack_a);
}

void	very_small_sorting(t_double_list **stack_a, t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*temp2;

	temp2 = ft_double_lstfirst(*stack_a);
	if (temp2->content > temp2->next->content)
		swap_list_stack_a(stack_a, compt);
	temp = ft_double_lstlast(*stack_a);
	if (temp->content < temp->previous->content)
		reverse_rotate_list_stack_a(stack_a, compt);
	temp2 = ft_double_lstfirst(*stack_a);
	if (temp2->content > temp->content)
		reverse_rotate_list_stack_a(stack_a, compt);
	if (temp2->content > temp2->next->content)
		swap_list_stack_a(stack_a, compt);
}

void	small_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	int				nb;

	if (ft_double_lstsize(*stack_a) < 4)
		very_small_sorting(stack_a, compt);
	else
	{
		while (ft_double_lstsize(*stack_a) != 3)
		{
			nb = smallest_number_list(stack_a);
			move_to_top(nb, stack_a, compt, 0);
			push_list(stack_b, stack_a, compt);
			printf("pb\n");
		}
		very_small_sorting(stack_a, compt);
		while (ft_double_lstsize(*stack_b) > 0)
		{
			push_list(stack_a, stack_b, compt);
			printf("pa\n");
		}
	}
}
