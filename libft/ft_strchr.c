/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:22:33 by wanton            #+#    #+#             */
/*   Updated: 2019/09/12 10:25:09 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*os;
	char	oc;

	os = (char *)s;
	oc = (char)c;
	while (*os != '\0')
	{
		if (*os == oc)
			return (os);
		os++;
	}
	if (*os == oc)
		return (os);
	return ((char *)NULL);
}
