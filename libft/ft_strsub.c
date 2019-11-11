/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:52:07 by wanton            #+#    #+#             */
/*   Updated: 2019/09/16 13:13:27 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = (char *)NULL;
	if (s)
	{
		if (!(res = ft_strnew(len)))
			return ((char *)NULL);
		i = 0;
		len = start + len;
		while (start < len)
		{
			res[i++] = s[start++];
		}
	}
	return (res);
}
