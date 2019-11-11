/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:48:59 by wanton            #+#    #+#             */
/*   Updated: 2019/09/14 11:31:25 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	res;

	if (s1 && s2)
	{
		res = ft_strncmp(s1, s2, n);
		if (res == 0)
			return (1);
		else
			return (0);
	}
	return ((int)NULL);
}
