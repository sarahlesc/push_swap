#include "../include/push_swap.h"

void	sort_with_median(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*cpy;
	int				median;

	temp = *stack_a;
	cpy = ft_double_lstcopy(temp);
	median = find_quartiles(2, cpy);
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
	printf("stack_b =\n");
	ft_double_print_list(*stack_b);
	printf("stack_a =\n");
	ft_double_print_list(*stack_a);
	ft_double_lstclear(&cpy, 0);
}
