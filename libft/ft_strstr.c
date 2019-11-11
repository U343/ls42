/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:06:18 by wanton            #+#    #+#             */
/*   Updated: 2019/09/12 11:21:15 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*ohay;
	const char	*onee;

	if (!*needle)
		return ((char *)haystack);
	ohay = haystack;
	onee = needle;
	while (*ohay != '\0')
	{
		if (*ohay == *onee)
		{
			if (ft_strncmp(ohay, onee, ft_strlen(onee)) == 0)
				return ((char *)ohay);
		}
		ohay++;
	}
	return ((char *)NULL);
}
