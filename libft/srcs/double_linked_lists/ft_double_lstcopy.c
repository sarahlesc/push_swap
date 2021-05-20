/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstcopy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:25:01 by llescure          #+#    #+#             */
/*   Updated: 2021/05/20 10:40:11 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_double_list	*ft_double_lstcopy(t_double_list *stack)
{
	t_double_list	*new;

	new = NULL;
	while (stack != NULL)
	{
		if (new == NULL)
			new = ft_double_lstnew(stack->content);
		else
			ft_double_lstadd_back(&new,
			ft_double_lstnew(stack->content));
		stack = stack->next;
	}
	return (new);
}
