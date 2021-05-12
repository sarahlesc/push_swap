/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:18:11 by llescure          #+#    #+#             */
/*   Updated: 2021/01/06 10:19:13 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "stdio.h"

unsigned long		ft_count_words2(char const *s, char sep)
{
	unsigned long	i;
@@ -32,13 +34,13 @@ unsigned long		ft_count_words2(char const *s, char sep)

int main(void)
{
	char	*string = "      split       this for   me  !       ";
	char	*string = "80aUh5NlgTu3AI 1laxVHGB GliqK3Qu4E z0kr7l PGxu gYc9b7Ps4Sy1f HjTZ0pBzG2qm v0a8MI7bArw UhFk3sezd20PMmfj g4ql9JBvoyiXws MVZhPtB CX38Q05Ucjq2Hf 7y9PGXij2aFtQ EArcMKn1 CRxiIXMrha1LF9Yp deLs0ZIWYQAR6FfN";
	unsigned long i;
	char **rslt;

	i = 0;
	rslt = ft_split(string, ' ');
	while (i < ft_count_words2(string, ' '))
	while (i <= ft_count_words2(string, ' '))
	{
		printf("%s\n", rslt[i]);
		i++;
	}
}
