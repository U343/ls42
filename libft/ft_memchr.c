/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:47:02 by wanton            #+#    #+#             */
/*   Updated: 2019/09/10 16:18:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*os;
	unsigned char	oc;

	os = (unsigned char *)s;
	oc = (unsigned char)c;
	while (n != 0)
	{
		if (*os++ == oc)
			return ((void *)--os);
		n--;
	}
	return ((void *)0);
}
