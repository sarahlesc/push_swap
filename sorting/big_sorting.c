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
