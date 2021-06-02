/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:28:46 by slescure          #+#    #+#             */
/*   Updated: 2021/06/02 13:28:46 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	reverse_rotate_list_stack_a(t_double_list **stack_a, t_compt *compt)
{
	t_double_list	*temp1;
	t_double_list	*temp2;
	int				store;

	if (ft_double_lstsize(*stack_a) == 0 || ft_double_lstsize(*stack_a) == 1)
		return (-1);
	temp1 = ft_double_lstlast(*stack_a);
	temp2 = ft_double_lstcopy(*stack_a);
	store = temp1->content;
	temp1 = ft_double_lstfirst(temp1);
	temp1->content = store;
	temp1 = temp1->next;
	while (temp2->next != NULL)
	{
		temp1->content = temp2->content;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	compt->value++;
	temp2 = ft_double_lstfirst(temp2);
	ft_double_lstclear(&temp2, 0);
	printf("rra\n");
	return (0);
}

int	reverse_rotate_list_stack_b(t_double_list **stack_b, t_compt *compt)
{
	t_double_list	*temp1;
	t_double_list	*temp2;
	int				store;

	if (ft_double_lstsize(*stack_b) == 0 || ft_double_lstsize(*stack_b) == 1)
		return (-1);
	temp1 = ft_double_lstlast(*stack_b);
	temp2 = ft_double_lstcopy(*stack_b);
	store = temp1->content;
	temp1 = ft_double_lstfirst(temp1);
	temp1->content = store;
	temp1 = temp1->next;
	while (temp2->next != NULL)
	{
		temp1->content = temp2->content;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	compt->value++;
	temp2 = ft_double_lstfirst(temp2);
	ft_double_lstclear(&temp2, 0);
	printf("rrb\n");
	return (0);
}

void	reverse_rotate_both(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	reverse_rotate_list_stack_a(stack_a, compt);
	reverse_rotate_list_stack_b(stack_b, compt);
	printf("rrr\n");
	compt->value--;
}
