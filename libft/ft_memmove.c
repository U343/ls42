/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:50:10 by wanton            #+#    #+#             */
/*   Updated: 2019/09/16 13:05:05 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	char		*s2;
	int			dir;

	dir = 1;
	if (dst == src)
		return (dst);
	else if (dst < src)
	{
		s1 = (char *)dst;
		s2 = (char *)src;
	}
	else if (dst > src)
	{
		s1 = (char *)dst + len - 1;
		s2 = (char *)src + len - 1;
		dir = -1;
	}
	while (len-- != 0)
	{
		*s1 = *s2;
		s1 += dir;
		s2 += dir;
	}
	return (dst);
}
