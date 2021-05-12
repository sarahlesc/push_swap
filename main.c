#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	int				i;
	t_double_list stack_a;
	t_double_list stack_b;

	if (argc == 1 || argc == 2)
		return ;
	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		nb_is_decim(argv[i]);
		check_duplicates_list(argv[i], argv, i);
		ft_double_lstadd_back(&stack_a, ft_double_lstnew((int)ft_atoi[argv[i]]));
		i++;
	}
	return (0);
}
