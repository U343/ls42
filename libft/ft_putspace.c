/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:25:51 by wanton            #+#    #+#             */
/*   Updated: 2019/11/25 13:25:51 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putspace(int n)
{
	int i;

	i = 0;
	while (i++ < n)
	{
		ft_putchar(' ');
	}
}
