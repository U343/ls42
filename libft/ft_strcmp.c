/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:22:10 by wanton            #+#    #+#             */
/*   Updated: 2019/09/12 10:59:33 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *os1;
	unsigned char *os2;

	os1 = (unsigned char *)s1;
	os2 = (unsigned char *)s2;
	while (*os1 == *os2 && *os1 != '\0' && *os2 != '\0')
	{
		os1++;
		os2++;
	}
	return (*os1 - *os2);
}
