/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:34:07 by wanton            #+#    #+#             */
/*   Updated: 2019/09/16 13:28:58 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	if (i > (i + 1))
		return ((char *)NULL);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return ((char *)NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
