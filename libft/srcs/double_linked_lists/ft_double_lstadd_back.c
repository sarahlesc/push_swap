/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstadd_back.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:04:32 by llescure          #+#    #+#             */
/*   Updated: 2021/05/14 11:05:07 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_double_lstadd_back(t_double_list **alst, t_double_list *new)
{
	t_double_list *temp;

	/*if (alst == NULL)
		return ;*/
	new->next = NULL;
	temp = *alst;
	if (temp == NULL)
	{
		new->previous = NULL;
		temp = new;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	new->previous = temp;
	temp->next = new;
}	
