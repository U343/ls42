/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:07:56 by wanton            #+#    #+#             */
/*   Updated: 2019/09/17 12:41:05 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void				ft_sort_int(int *t, size_t size)
{
	size_t	i;
	int		flag;

	if (t)
	{
		flag = 0;
		while (flag == 0)
		{
			flag = 1;
			i = 0;
			while (i < (size - 1))
			{
				if (t[i] > t[i + 1])
				{
					ft_swap(&t[i], &t[i + 1]);
					flag = 0;
				}
				i++;
			}
		}
	}
}
