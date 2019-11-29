/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:50:21 by wanton            #+#    #+#             */
/*   Updated: 2019/11/29 12:27:46 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Печтает элементы списка tmp в многоколоночном формате
**len вместо row
*/

void		print_list(t_file *tmp, __uint16_t flag, int maxlen, int l)
{
	t_file			*p;
	struct winsize	w;
	int				col;
	int				i;
	int 			kkk;
	int				num;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	col = w.ws_col / maxlen + (w.ws_col / maxlen == 0 ? 1 : 0);
	l = l / col + (l % col == 0 ? 0 : 1);
	kkk = l; // нужно будет избавиться
	num = 0;
	//printf("col = %d\n", col);
	//printf("row = %d\n", len);
	while (l-- != 0)
	{
		i = 0;
		while (i++ < col)
		{
			if ((p = ft_take_elem(tmp, num)))
			{
				ft_putstr(p->name);
				ft_putspace((int)(maxlen - ft_strlen(p->name)));
				num = num + kkk;
			}
			else
				break ;
		}
		num = (num - (kkk * --i)) + 1;
		ft_putchar('\n');
	}
}

void		recursive_print(t_file	*tmp, int flag)
{
	
}

void		test_print(t_file	*tmp) // тестовый вывод списка (потом удалить)
{
	t_file	*p;

	p = tmp;
	while (p)
	{
		printf("%s\t|dir = %d\tfile = %d\tlink = %d\n",p->name, p->is_dir,
			   p->is_reg, p->is_link);
		p = p->next;
	}
}

int			main_print(t_file **head, t_file **tmp, int flag)
{
	int n;
	int len;

	n = open_dir((*tmp)->name, head, flag, &len);
	if (!(more_info(*head, flag)))
	{
		ft_putstr("more info error\n");
		free_list(head);
		free_list(tmp);
		return (0);
	}
	sort_list(head, flag);
	//move_dir(head);
	print_list(*head, flag, (n+2), len);
	//test_print(*head);
	return (1);
}