/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:12:40 by wanton            #+#    #+#             */
/*   Updated: 2019/12/05 13:39:21 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int 	open_dir(const char *adr, t_file **head, __uint16_t flag, int *l)
{
	DIR				*dir;
	int 			maxlen;
	t_file			*p;
	struct dirent	*res;

	if (!(dir = opendir(adr)))
	{
		ft_putstr("Cannot open directory ");
		ft_putstr(adr);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		return (0);
	}
	while ((res = readdir(dir)) && (flag & LS_A) == 0)
	{
		if (res->d_name[0] != '.')
			break;
	}
	if (!res)
		return (0);
	if (!(*head = new_list_elem_file(res->d_name, res)))
		return (0);
	maxlen = (*head)->len_name;
	*l = 1;
	while ((res = readdir(dir)))
	{
		if ((res->d_name[0] != '.' || (flag & LS_A)))
		{
			if (!(p = new_list_elem_file(res->d_name, res)))
				return (0);
			if (maxlen < p->len_name)
				maxlen = p->len_name;
			ft_lstadd_file(head, p);
			(*l)++;
		}
	}
	if ((closedir(dir)))
	{
		ft_putstr("Could not close ");
		ft_putstr(adr);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		return (0);
	}
	return (maxlen);
}

/*
**Заполняет список элементов расширенными параметрами об элементах
*/

int 	more_info(t_file *tmp, __uint16_t flag)
{
	char 		*name;
	t_file		*p;
	struct stat	*buf;


	p = tmp;
	while (p)
	{
		if (!(buf = (struct stat *)malloc(sizeof(struct stat))))
			return (0);
		if (!(name = (char *)malloc(sizeof(char) * 1024)))
			return (0);
		name = ft_strcpy(name, p->path);
		name = ft_strcat(name, p->name);
		if ((stat(name, buf)) == -1)
		{
			free(buf);
			return (0);
		}
		list_elem_info(p, *buf);
		p = p->next;
		free(buf);
		free(name);
	}
	return (1);
}