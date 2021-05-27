#include "include/push_swap.h"

int		main(int argc, char **argv)
{
	int				i;
	t_double_list	*stack_a;
	t_compt			compt;

	compt.value = 0;
	if (argc == 1 || argc == 2)
		return (0);
	nb_is_decim(argv[1], &stack_a, 1);
	stack_a = ft_double_lstnew(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		nb_is_decim(argv[i], &stack_a, i);
		check_duplicates_list(argv[i], argv, i, &stack_a);
		ft_double_lstadd_back(&stack_a, ft_double_lstnew(ft_atoi(argv[i])));
		i++;
	}
	push_swap_stacks(&stack_a, &compt);
	printf("compteur = %d\n", compt.value);
	ft_double_lstclear(&stack_a, 0);
	return (0);
}

void	push_swap_stacks(t_double_list **stack_a, t_compt *compt)
{
	t_double_list	*stack_b;

	stack_b = NULL;
	check_list(stack_a);
	if (stack_is_sorted(*stack_a) == 0)
	{
		printf("OK\n");
		exit(0);
	}
	call_push_swap(stack_a, &stack_b, compt);
	printf("stack_a = \n");
	ft_double_print_list(*stack_a);
	if (stack_is_sorted(*stack_a) == -1)
	{
		printf("KO\n");
		exit(0);
	}
	printf("OK\n");
}
