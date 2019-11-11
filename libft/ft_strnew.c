/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:00:16 by wanton            #+#    #+#             */
/*   Updated: 2019/09/14 15:55:12 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)NULL;
	if (size < (size + 1))
	{
		if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_bzero(res, (size + 1));
	}
	return (res);
}
