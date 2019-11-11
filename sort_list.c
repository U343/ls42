/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:16:26 by wanton            #+#    #+#             */
/*   Updated: 2019/11/11 12:29:27 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Нужет для того чтобы менять местами name элементов списка
*/

static void		ft_swap(char **s1, char **s2)
{
	char *buf;

	buf = *s1;
	*s1 = *s2;
	*s2 = buf;
}

/*
**Сортирует список t_file по возрастанию
*/

void			sort_list(t_file **tmp)
{
	t_file *p;
	int		flag;

	flag = 0;
	while (flag == 0)
	{
		p = *tmp;
		flag = 1;
		while (p && p->next)
		{
			if (ft_strcmp(p->name, p->next->name) > 0)
			{
				ft_swap(&p->name, &p->next->name);
				flag = 0;
			}
			p = p->next;
		}
	}
}