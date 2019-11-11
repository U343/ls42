/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:11:01 by wanton            #+#    #+#             */
/*   Updated: 2019/09/12 10:33:51 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*os;
	char	*res;
	char	oc;

	os = (char *)s;
	oc = (char)c;
	res = (char *)NULL;
	while (*os != '\0')
	{
		if (*os == oc)
			res = os;
		os++;
	}
	if (*os == oc)
		res = os;
	return (res);
}
