#include "include/push_swap.h"

void	check_list(t_double_list **stack_a)
{
	t_double_list	*temp;

	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->content < -2147483647
			|| temp->content > 2147483647)
			print_error(stack_a);
		temp = temp->next;
	}
}

void	check_duplicates_list(char *str, char **argv, int i, t_double_list
	**stack_a)
{
	int	j;
	int	value;

	j = 1;
	while (j < i)
	{
		if (ft_strlen(str) == ft_strlen(argv[j]))
		{
			value = ft_strncmp(str, argv[j], ft_strlen(str));
			if (value == 0)
				print_error(stack_a);
		}
		j++;
	}
}

void	nb_is_decim(char *str, t_double_list **stack_a, int true_false)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (ft_isdigit(str[i]) == 1 || str[i] == '-')
			i++;
		if (str[i] != ' ' && str[i] != '\0' && true_false != 1)
			print_error(stack_a);
		else if (str[i] != ' ' && str[i] != '\0' && true_false == 1)
		{
			printf("Error\n");
			exit(0);
		}
	}
}

void	print_error(t_double_list **stack_a)
{
	printf("Error\n");
	if (*stack_a != NULL && stack_a != NULL)
		ft_double_lstclear(stack_a, 0);
	exit(0);
}
