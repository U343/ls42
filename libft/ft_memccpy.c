/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:38:06 by wanton            #+#    #+#             */
/*   Updated: 2019/09/13 12:29:11 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*odst;
	unsigned char	*osrc;
	unsigned char	oc;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	odst = (unsigned char *)dst;
	osrc = (unsigned char *)src;
	oc = (unsigned char)c;
	while (i++ < n)
	{
		if ((*odst++ = *osrc++) == oc)
			return (odst);
	}
	return (0);
}
