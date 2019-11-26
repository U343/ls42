/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:50:29 by wanton            #+#    #+#             */
/*   Updated: 2019/11/25 11:50:29 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(const char *s1, int *len)
{
	char	*res;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	*len = (int)i;
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