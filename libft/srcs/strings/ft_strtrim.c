/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:50:09 by slescure          #+#    #+#             */
/*   Updated: 2021/06/02 13:50:10 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

unsigned long	ft_trim_beg(char const *s1, char const *set)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		while (set[j] == s1[i])
		{
			if (s1[i] == '\0')
				return (i);
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

unsigned long	ft_trim_last(char const *s1, char const *set)
{
	unsigned long	i;
	unsigned long	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] != 0)
	{
		while (set[j] == s1[i])
		{
			if (i == 0)
				return (i);
			i--;
			j = 0;
		}
		j++;
	}
	return (ft_strlen(s1) - i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char						*rslt;
	unsigned long				i;
	unsigned long				j;
	unsigned long				cara;

	cara = ft_strlen(s1) - ft_trim_beg(s1, set) - ft_trim_last(s1, set);
	rslt = malloc(sizeof(char) * cara + 1);
	if (rslt == NULL)
		return (NULL);
	i = ft_trim_beg(s1, set);
	j = 0;
	while (i != (ft_strlen(s1) - ft_trim_last(s1, set)))
	{
		rslt[j] = s1[i];
		i++;
		j++;
	}
	rslt[j] = '\0';
	return (rslt);
}
