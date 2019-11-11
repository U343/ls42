/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:22:45 by wanton            #+#    #+#             */
/*   Updated: 2019/09/10 14:07:48 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*odst;
	unsigned char	*osrc;

	i = 0;
	if (dst == src)
		return (dst);
	odst = (char *)dst;
	osrc = (unsigned char *)src;
	while (i < n)
	{
		odst[i] = osrc[i];
		i++;
	}
	return (dst);
}
