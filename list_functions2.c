/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:15:36 by wanton            #+#    #+#             */
/*   Updated: 2019/11/26 12:32:56 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Функця для поиска n-го элемента списка t_file
*/

t_file	*ft_take_elem(t_file *head, int n)
{
	int		i;
	t_file	*p;

	i = 0;
	p = head;
	while (i++ < n && p)
	{
		p = p->next;
	}
	if (!p)
		return (NULL);
	return (p);
}

/*
**Очищает память выделенную под элементы списка t_file и name
*/

void	free_list(t_file **tmp)
{
	t_file	*p;
	t_file	*d;

	p = *tmp;
	*tmp = NULL;
	while (p)
	{
		d = p;
		p = p->next;
		free(d->name);
		d->next = NULL;
		free(d);
	}
	free(*tmp);
}
