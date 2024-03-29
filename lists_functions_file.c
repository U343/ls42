/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:16:53 by wanton            #+#    #+#             */
/*   Updated: 2019/12/05 13:28:45 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				get_full_path(char res[PATH_MAX], const char *path,
								 const char *d_n)
{
	int 	i;
	int 	i2;

	i = -1;
	i2 = -1;
	while (path[++i])
		res[i] = path[i];
	if (i && i < PATH_MAX)
		if (res[i - 1] != '/')
			res[i++] = '/';
	while (d_n[++i2])
		res[i++] = d_n[i2];
	if (i < PATH_MAX)
		res[i] = '\0';
	return ((i < PATH_MAX) ? 1 : 0);
}

/*
**Используется при вызове флага l и t
**Создаёт тотже элемент списка, но с расширенными параментрами
*/

void		list_elem_info(t_file *tmp, struct stat buf)
{
	tmp->is_dir = (S_ISDIR(buf.st_mode) == 1 ? 1 : 0);
	tmp->is_link = (S_ISLNK(buf.st_mode) == 1 ? 1 : 0);
	tmp->is_reg = (S_ISREG(buf.st_mode) == 1 ? 1 : 0);
}

/*
**Создает новый элемент списка
*/

t_file		*new_list_elem_file(char *s, struct dirent *res)
{
	t_file	*new;
	int		ln;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (!(new->name = ft_strldup(s, &ln)))
		return (NULL);
	new->is_dir = res->d_type & DT_DIR;
	new->len_name = ln;
	new->next = NULL;
	return (new);
}

/*
**Добавляет элементы в конец списка tmp
*/

void		ft_lstadd_file(t_file **alst, t_file *new)
{
	t_file	*p;

	p = *alst;
	while (p->next)
	{
		p = p->next;
	}
	p->next = new;
}

/*
**Формирует список файлов и диррикторий
**Если аргументы не переданы, то создается один элемент списка со значеним '.'
*/

int			list_add(t_file **tmp, int ac, char **av, int n)
{
	t_file	*p;

	/*if (ac == n)
	{
		if (!(*tmp = new_list_elem_file(".")))
			return (0);
		return (1);
	}*/
	/*if (!(*tmp = new_list_elem_file(av[n++])))
		return (0);
	while (--ac > n)
	{
		if (!(p = new_list_elem_file(av[n++])))
			return (0);
		ft_lstadd_file(tmp, p);
	}*/
	return (1);
}
