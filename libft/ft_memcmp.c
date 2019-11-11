/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:00:50 by wanton            #+#    #+#             */
/*   Updated: 2019/09/10 16:57:24 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *os1;
	unsigned char *os2;

	os1 = (unsigned char *)s1;
	os2 = (unsigned char *)s2;
	while (n--)
	{
		if (*os1 != *os2)
			return (*os1 - *os2);
		os1++;
		os2++;
	}
	return (0);
}
