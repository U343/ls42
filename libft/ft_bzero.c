/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:38:18 by wanton            #+#    #+#             */
/*   Updated: 2019/09/16 12:41:15 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	if (n != 0)
	{
		i = 0;
		tmp = (unsigned char *)s;
		while (i < n)
		{
			tmp[i] = '\0';
			i++;
		}
	}
}