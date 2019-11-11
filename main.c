/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:55:00 by wanton            #+#    #+#             */
/*   Updated: 2019/11/11 12:59:19 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	main(int ac, char **av)
{
	t_file	*tmp;
	int 	res;

	if(!(list_add(&tmp, ac, av)))
	{
		free_list(&tmp);
		ft_putstr("malloc error\n");
		return (0);
	}
	sort_list(&tmp);
	print_list(tmp);
	return (0);
}