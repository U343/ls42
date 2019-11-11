/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:47:38 by wanton            #+#    #+#             */
/*   Updated: 2019/09/14 11:57:04 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	char	*res;

	res = (char *)NULL;
	if (s1 && s2)
	{
		i = 0;
		size = ft_strlen(s1) + ft_strlen(s2);
		if (size > (size + 1))
			return ((char *)NULL);
		if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = '\0';
		res = ft_strcat(res, s2);
	}
	return (res);
}
