/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:25:50 by wanton            #+#    #+#             */
/*   Updated: 2019/09/16 13:17:17 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_n(long n)
{
	int i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int nbr)
{
	size_t	size;
	char	*res;
	int		neg;
	long	onbr;

	neg = 0;
	if ((onbr = (long)nbr) < 0)
	{
		onbr = onbr * (-1);
		neg = 1;
	}
	size = count_n(onbr) + neg;
	if (size > (size + 1))
		return ((char *)NULL);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return ((char *)NULL);
	res[size] = '\0';
	while (size != 0)
	{
		res[--size] = (onbr % 10) + '0';
		onbr = onbr / 10;
	}
	if (neg == 1)
		res[0] = '-';
	return (res);
}
