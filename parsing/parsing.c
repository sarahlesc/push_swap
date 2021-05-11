#include "push_swap.h"

void 	check_list(t_list *stack_a, t_list *stack_b)
{
	if (stack_b != NULL)
		print_error();
	while (stack_a != NULL)
	{
		if (stack_a->content < -2147483647 || stack_a > 2147483647)
			print_error();
		stack_a = stack_a->next;
	}
	check_duplicates_list(stack_a);
}

void 	check_duplicates_list(t_double_list *stack_a)
{
	t_double_list	*list;
	int				compt;
	int				i;

	list = stack_a;
	compt = 0;
	while (stack_a != NULL)
	{
		i = -1;
		compt++;
		while (++i < compt)
			list = list->next;
		while (list != NULL)
		{
			if (stack_a->content == list->content)
				print_error();
			list = list->next;
		}
		stack_a = stack_a->next;
		ft_double_lstfirst(list); // retour au debut de list
	}
}

int nb_is_decim(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		while (ft_isdigit(str[i]) == 1)
			i++;
		if (str[i] != ' ' || str[i] != '\0')
			print_error();
	}
	return (1);
}

void 	print_error()
{
	printf("Error\n");
	exit (0);
}
