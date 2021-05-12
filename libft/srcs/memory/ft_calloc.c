/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 23:11:51 by llescure          #+#    #+#             */
/*   Updated: 2021/05/06 15:22:52 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void				*ptr;
	char				*str;
	unsigned int		i;

	i = 0;
	if (!(ptr = malloc(count * size)))
		return (NULL);
	str = ptr;
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
