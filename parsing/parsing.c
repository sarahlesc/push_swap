/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:28:43 by slescure          #+#    #+#             */
/*   Updated: 2021/06/02 14:35:49 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_number(long number, t_double_list **stack_a)
{
	if (number < -2147483647 || number > 2147483647)
		print_error(stack_a);
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
		while (str[i] == '-')
			i++;
		if (i > 1)
			print_error(stack_a);
		while (ft_isdigit(str[i]) == 1)
			i++;
		if (str[i] != ' ' && str[i] != '\0' && true_false != 1)
			print_error(stack_a);
		else if (str[i] != ' ' && str[i] != '\0' && true_false == 1)
			print_error(stack_a);
	}
}

void	print_error(t_double_list **stack_a)
{
	printf("Error\n");
	if (*stack_a != NULL && stack_a != NULL)
		ft_double_lstclear(stack_a, 0);
	exit(0);
}
