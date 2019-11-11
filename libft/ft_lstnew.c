/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:54:22 by wanton            #+#    #+#             */
/*   Updated: 2019/09/15 21:35:44 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void	const *con, size_t con_size)
{
	t_list	*res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return ((t_list *)NULL);
	if (!con || !con_size)
	{
		res->content = NULL;
		res->content_size = 0;
		res->next = NULL;
		return (res);
	}
	if (!(res->content = (void *)malloc(con_size)))
	{
		free(res);
		return ((t_list *)NULL);
	}
	res->content = ft_memcpy(res->content, con, con_size);
	res->content_size = con_size;
	res->next = NULL;
	return (res);
}
