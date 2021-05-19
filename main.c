#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	int				i;
	t_double_list	*stack_a;
	t_double_list	*stack_b;
	t_compt			compt;

	compt.value = 0;
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
	printf("stack_a = \n");
	ft_double_print_list(stack_a);
	call_push_swap(&stack_a, &stack_b, &compt);
	printf("\n");
	printf("stack_a = \n");
	ft_double_print_list(stack_a);
	printf("stack_b = \n");
	ft_double_print_list(stack_b);
	printf("compteur = %d\n", compt.value);
	stack_is_sorted(stack_a);
	return (0);
}
