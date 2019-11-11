/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:55:00 by wanton            #+#    #+#             */
/*   Updated: 2019/11/11 13:57:54 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	main(int ac, char **av)
{
	t_file	*tmp;
	t_file	*p;
	int 	res;

	if(!(list_add(&tmp, ac, av)))
	{
		free_list(&tmp);
		ft_putstr("malloc error\n");
		return (0);
	}
	sort_list(&tmp);
	//print_list(tmp);
	p = tmp;
	while (p)
	{
		open_dir(p->name);
		p = p->next;
	}
	return (0);
}