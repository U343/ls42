/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:37:41 by wanton            #+#    #+#             */
/*   Updated: 2019/09/13 12:54:26 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*os1;
	unsigned char	*os2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 1;
	os1 = (unsigned char *)s1;
	os2 = (unsigned char *)s2;
	while (*os1 == *os2 && *os1 != '\0' && *os2 != '\0' && i < n)
	{
		os1++;
		os2++;
		i++;
	}
	return (*os1 - *os2);
}
