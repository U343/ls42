/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:12:40 by wanton            #+#    #+#             */
/*   Updated: 2019/11/11 13:56:43 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	open_dir(char *adr)
{
	DIR				*dir;
	struct dirent	*res;
	struct stat		buf;

	if(!(dir = opendir(adr)))
		return (0);
	while ((res = readdir(dir)))
	{
		if (res->d_name[0] != '.')
		{
			ft_putstr(res->d_name);
			ft_putchar('\n');
		}
	}
	ft_putchar('\n');
	ft_putstr("-----------------------------------------------");
	ft_putchar('\n');
	closedir(dir);
	return (1);
}