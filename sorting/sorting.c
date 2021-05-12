#include "push_swap.h"

void 	type_sorting(t_double_list **stack_a, t_double_list **stack_b)
{
	if (ft_double_lstsize(*stack_a) <= 10)
		small_sorting(*stack_a, *stack_b);
	if (ft_double_lstsize(*stack_a) > 10 && ft_double_lstsize(*stack_a) <= 100)
		medium_sorting(*stack_a, *stack_b);
	if (ft_double_lstsize(*stack_a) > 100 && ft_double_lstsize(*stack_a) <= 500)
		large_sorting(*stack_a, *stack_b);
	else
		print_error();
}
