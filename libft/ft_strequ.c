/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:43:05 by wanton            #+#    #+#             */
/*   Updated: 2019/09/14 11:31:12 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	res;

	if (s1 && s2)
	{
		res = ft_strcmp(s1, s2);
		if (res == 0)
			return (1);
		else
			return (0);
	}
	return ((int)NULL);
}
