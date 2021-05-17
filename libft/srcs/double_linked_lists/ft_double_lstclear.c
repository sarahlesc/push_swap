/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstclear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:35:01 by llescure          #+#    #+#             */
/*   Updated: 2021/05/17 12:14:59 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_double_lstclear(t_double_list **lst, int pos)
{
	t_double_list	*temp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_double_lstdelone(lst, pos);
		*lst = temp;
		pos++;
	}
}
