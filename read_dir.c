/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:12:40 by wanton            #+#    #+#             */
/*   Updated: 2019/11/25 12:14:34 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int 	open_dir(char *adr, t_file **head, int flag, int *len)
{
	DIR				*dir;
	int 			maxlen;
	t_file			*p;
	struct dirent	*res;

	if (!(dir = opendir(adr)) || !(res = readdir(dir)))
		return (0);
	if (!(*head = new_list_elem_file(res->d_name)))
		return (0);
	maxlen = (*head)->len_name;
	*len = 1;
	while ((res = readdir(dir)))
	{
		if(!(p = new_list_elem_file(res->d_name)))
			return (0);
		if (maxlen  < p->len_name)
			maxlen = p->len_name;
		ft_lstadd_file(head, p);
		(*len)++;
	}
	return (maxlen);
}