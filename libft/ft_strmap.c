/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:52:54 by wanton            #+#    #+#             */
/*   Updated: 2019/09/16 13:11:37 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	res = NULL;
	if (s)
	{
		if (!(res = ft_strdup(s)))
			return ((char *)NULL);
		i = 0;
		while (res[i])
		{
			res[i] = f(res[i]);
			i++;
		}
	}
	return (res);
}
