/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:24:01 by wanton            #+#    #+#             */
/*   Updated: 2019/09/14 12:13:03 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	st;
	size_t	ed;
	size_t	i;
	char	*res;

	res = (char *)NULL;
	if (s)
	{
		i = 0;
		st = 0;
		ed = 0;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		{
			i++;
		}
		st = i;
		ed = ft_strlen(s) - 1;
		while ((s[ed] == ' ' || s[ed] == '\n' || s[ed] == '\t') && ed >= st)
		{
			ed--;
		}
		res = ft_strsub(s, st, ++ed - st);
	}
	return (res);
}
