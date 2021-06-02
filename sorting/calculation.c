/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:41:12 by slescure          #+#    #+#             */
/*   Updated: 2021/06/02 13:41:13 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	smallest_number_list(t_double_list **stack_a)
{
	t_double_list	*temp;
	int				nb;

	temp = ft_double_lstfirst(*stack_a);
	nb = temp->content;
	while (temp->next != NULL)
	{
		if (nb > temp->next->content)
			nb = temp->next->content;
		temp = temp->next;
	}
	return (nb);
}

int	biggest_number_list(t_double_list **stack_a)
{
	t_double_list	*temp;
	int				nb;

	temp = ft_double_lstfirst(*stack_a);
	nb = temp->content;
	while (temp->next != NULL)
	{
		if (nb < temp->next->content)
			nb = temp->next->content;
		temp = temp->next;
	}
	return (nb);
}

int	divide_stack_by_three(double q, t_double_list *stack)
{
	int				i;
	double			quartile;
	t_double_list	*temp;

	i = 0;
	temp = ft_double_lstfirst(stack);
	quartile = ft_double_lstsize(stack) * (q / 3);
	swap_sort(&temp);
	while (i < quartile)
	{
		temp = temp->next;
		i++;
	}
	return (temp->content);
}

int	divide_stack_by_eight(double q, t_double_list *stack)
{
	int				i;
	double			quintile;
	t_double_list	*temp;

	i = 0;
	temp = ft_double_lstfirst(stack);
	quintile = ft_double_lstsize(stack) * (q / 8);
	swap_sort(&temp);
	while (i < quintile)
	{
		temp = temp->next;
		i++;
	}
	return (temp->content);
}

int	smallest_to_use(int smallest, int biggest, t_double_list **stack)
{
	int				i;
	int				j;
	t_double_list	*temp;

	temp = *stack;
	i = 0;
	j = 0;
	while (temp->content != smallest)
	{
		temp = temp->next;
		i++;
	}
	temp = ft_double_lstfirst(temp);
	while (temp->content != biggest)
	{
		temp = temp->next;
		j++;
	}
	temp = ft_double_lstfirst(temp);
	if (compare_nb_operations(i, j, stack) == 1)
		return (1);
	else
		return (2);
}
