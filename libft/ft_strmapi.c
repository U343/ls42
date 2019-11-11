/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:52:54 by wanton            #+#    #+#             */
/*   Updated: 2019/09/16 13:12:20 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	res = (char *)NULL;
	if (s)
	{
		if (!(res = ft_strdup(s)))
			return ((char *)NULL);
		i = 0;
		while (res[i])
		{
			res[i] = f(i, res[i]);
			i++;
		}
	}
	return (res);
}
