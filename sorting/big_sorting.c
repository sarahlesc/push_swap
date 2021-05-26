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
	median = find_quartiles(2, cpy);
	quartile_one = find_quartiles(1, cpy);
	quartile_three = find_quartiles(3, cpy);
	printf("quartile one = %i\n", quartile_one);
	printf("quartile three = %i\n", quartile_three);
	while (temp != NULL)
	{
		if (temp->content <= median)
		{
			if (temp->previous != NULL)
				move_to_top(temp->content, stack_a, compt);
			push_list_to_stack_b(stack_b, stack_a, compt);
			temp = *stack_a;
		}
		else
			temp = temp->next;
	}
	temp = ft_double_lstfirst(temp);
	push_all_to_stack_a(stack_a, stack_b, compt);
	ft_double_lstclear(&cpy, 0);
}
