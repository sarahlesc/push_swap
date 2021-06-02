/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:28:02 by slescure          #+#    #+#             */
/*   Updated: 2021/06/02 14:14:19 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	int				i;
	t_double_list	*stack_a;
	t_compt			compt;

	compt.value = 0;
	stack_a = NULL;
	if (argc == 1)
		return (0);
	nb_is_decim(argv[1], &stack_a, 1);
	check_number(ft_atoi(argv[1]), &stack_a);
	if (argc == 2)
		return (0);
	stack_a = ft_double_lstnew(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		nb_is_decim(argv[i], &stack_a, i);
		check_number(ft_atoi(argv[i]), &stack_a);
		check_duplicates_list(argv[i], argv, i, &stack_a);
		ft_double_lstadd_back(&stack_a, ft_double_lstnew(ft_atoi(argv[i])));
		i++;
	}
	push_swap_stacks(&stack_a, &compt);
	ft_double_lstclear(&stack_a, 0);
	return (0);
}

void	push_swap_stacks(t_double_list **stack_a, t_compt *compt)
{
	t_double_list	*stack_b;

	stack_b = NULL;
	if (stack_is_sorted(*stack_a) == 0)
	{
		if (*stack_a != NULL && stack_a != NULL)
			ft_double_lstclear(stack_a, 0);
		exit(0);
	}
	call_push_swap(stack_a, &stack_b, compt);
}
