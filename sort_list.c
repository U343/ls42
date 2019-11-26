/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:16:26 by wanton            #+#    #+#             */
/*   Updated: 2019/11/26 15:27:05 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Нужет для того чтобы менять местами name элементов списка
*/

static void			ft_swap(t_file *p1, t_file *p2)
{
	p1->next = p2->next;
	p2->next = p1;
}

/*
**Сортирует список t_file по возрастанию
**Меняет местами именно элементы списка
*/

void				sort_list(t_file **lst, __uint16_t flag)
{
	t_file	*p;
	t_file	*u3;
	int		check;

	check = 0;
	while (check == 0)
	{
		p = *lst;
		check = 1;
		u3 = 0;
		while (p && p->next)
		{
			if (ft_strcmp(p->name, p->next->name) > 0)
			{
				check = 0;
				*lst = (u3 == 0 ? p->next : *lst);
				if (u3 != 0)
					u3->next = p->next;
				ft_swap(p, p->next);
			}
			u3 = p;
			p = p->next;
		}
	}
}

void				move_dir(t_file	**lst)
{
	t_file	*p;
	t_file	*u3;
	t_file	*tmp;
	int  	i;
	int		len;

	i = 0;
	len = 0;
	p = *lst;
	while (p)
	{
		if (p->is_dir == 1)
			len++;
		p = p->next;
	}
	while (i++ < len)
	{
		u3 = NULL;
		p = *lst;
		while (p)
		{
			if (p->is_dir == 1)
			{
				tmp = p;
				if (u3 == NULL)
					*lst = p->next;
				while (p->next)
					p = p->next;
				p->next = tmp;
				break;
			}
			u3 = p;
			p = p->next;
		}
	}
}




