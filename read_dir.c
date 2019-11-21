/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:12:40 by wanton            #+#    #+#             */
/*   Updated: 2019/11/20 16:56:50 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int 	open_dir(char *adr, t_file **head)
{
	DIR				*dir;
	struct dirent	*res;
	struct stat		buf;
	t_file			*p;

	if(!(dir = opendir(adr)))
		return (0);
	res = readdir(dir);
	stat(res->d_name, &buf);
	if (!(*head = new_list_elem_file2(res->d_name, buf)))
		return (0);
	while ((res = readdir(dir)))
	{
		stat(res->d_name, &buf);
		if (!(p = new_list_elem_file2(res->d_name, buf)))
			return (0);
		ft_lstadd_file(head, p);
	}
	ft_putchar('\n');
	closedir(dir);
	return (1);
}