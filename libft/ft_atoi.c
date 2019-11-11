/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:15:25 by wanton            #+#    #+#             */
/*   Updated: 2019/09/14 16:36:16 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		check_res(unsigned long long res, int neg)
{
	if (res > 9223372036854775807UL)
	{
		if (neg == 1)
			res = -1;
		else
			res = 0;
	}
	return (res);
}

int				ft_atoi(const char *str)
{
	char				*s;
	int					neg;
	unsigned long long	res;

	s = (char *)str;
	neg = 1;
	res = 0;
	while (ft_isspace(*s))
	{
		s++;
	}
	if (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			neg = -1;
	}
	while (ft_isdigit(*s))
	{
		res *= 10;
		res += *s++ - '0';
	}
	res = check_res(res, neg);
	return (res * neg);
}
