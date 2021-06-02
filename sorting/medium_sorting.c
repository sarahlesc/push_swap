/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:41:19 by slescure          #+#    #+#             */
/*   Updated: 2021/06/02 13:41:20 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	medium_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	t_double_list	*temp;
	t_double_list	*cpy;

	temp = *stack_a;
	cpy = ft_double_lstcopy(temp);
	compt->chunk_one = divide_stack_by_three(1, cpy);
	compt->chunk_two = divide_stack_by_three(2, cpy);
	compt->chunk_three = biggest_number_list(stack_a);
	move_stack_medium(compt->chunk_three, stack_a, stack_b, compt);
	move_stack_medium(compt->chunk_two, stack_a, stack_b, compt);
	move_stack_medium(compt->chunk_one, stack_a, stack_b, compt);
	temp = *stack_a;
	while (temp->content != smallest_number_list(stack_a))
		reverse_rotate_list_stack_a(stack_a, compt);
	ft_double_lstclear(&cpy, 0);
}

void	move_stack_medium(int pivot, t_double_list **stack_a,
		t_double_list **stack_b, t_compt *compt)
{
	t_double_list	*temp;
	int				min;

	temp = *stack_a;
	if (pivot == compt->chunk_one)
		min = smallest_number_list(stack_a);
	else if (pivot == compt->chunk_two)
		min = compt->chunk_one;
	else if (pivot == compt->chunk_three)
		min = compt->chunk_two;
	while (temp != NULL)
	{
		if (temp->content <= pivot && temp->content >= min)
		{
			if (temp->previous != NULL)
				move_to_top_stack_a(temp->content, stack_a, compt, 0);
			push_list_to_stack_b(stack_b, stack_a, compt);
			temp = *stack_a;
		}
		else
			temp = temp->next;
	}
	while (ft_double_lstsize(*stack_b) > 0)
		sort_stack_b(stack_a, stack_b, compt);
}
