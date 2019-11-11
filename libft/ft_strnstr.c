/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:48:58 by wanton            #+#    #+#             */
/*   Updated: 2019/09/15 20:46:42 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	const char	*onee;
	char		*ohay;
	size_t		i;
	size_t		end;

	if (!*n)
		return ((char *)h);
	i = 0;
	ohay = (char *)h;
	onee = n;
	if (ft_strlen(ohay) < ft_strlen(onee) || ft_strlen(onee) > len)
		return ((char *)NULL);
	end = len - ft_strlen(onee);
	while (*ohay != '\0' && i++ <= end)
	{
		if (*ohay == *onee)
		{
			if (ft_strncmp(ohay, onee, ft_strlen(onee)) == 0)
				return (ohay);
		}
		ohay++;
	}
	return ((char *)NULL);
}
