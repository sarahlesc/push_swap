#include "include/push_swap.h"

int		main(int argc, char **argv)
{
	int				i;
	t_double_list *stack_a;
	t_double_list *stack_b;

	if (argc == 1 || argc == 2)
		return (0);
	nb_is_decim(argv[1]); 
	stack_a = ft_double_lstnew(ft_atoi(argv[1]));
	stack_b = NULL;
	i = 2;
	while (i < argc)
	{
		nb_is_decim(argv[i]);
		check_duplicates_list(argv[i], argv, i);
		ft_double_lstadd_back(&stack_a, ft_double_lstnew(ft_atoi(argv[i])));
		i++;
	}
	check_list(stack_a);
	ft_double_print_list(stack_a);
	reverse_rotate_list(&stack_a);
//	push_list(&stack_b, &stack_a);
	ft_double_print_list(stack_a);
	//call_push_swap(&stack_a, &stack_b);
	return (0);
}
