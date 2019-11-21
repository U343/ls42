/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:16:53 by wanton            #+#    #+#             */
/*   Updated: 2019/11/21 12:22:28 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Используется при вызове флага l и t
**Создаёт тотже элемент списка, но с расширенными параментрами
*/

t_file		*new_list_elem_file2(char *s, struct stat buf)
{
	t_file *new;

	if (!(new = (t_file *) malloc(sizeof(t_file))))
		return (NULL);
	if (!(new->name = ft_strdup(s)))
		return (NULL);
	new->next = NULL;
	new->is_dir = (S_ISDIR(buf.st_mode) == 1 ? 1 : 0);
	new->is_link = (S_ISLNK(buf.st_mode) == 1 ? 1 : 0);
	new->is_reg = (S_ISREG(buf.st_mode) == 1 ? 1 : 0);
	return (new);
}

/*
**Создает новый элемент списка
*/

t_file		*new_list_elem_file(char *s)
{
	t_file	*new;

	if(!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if(!(new->name = ft_strdup(s)))
		return (NULL);
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
		p=p->next;
	}
	p->next = new;
}

/*
**Формирует список файлов и диррикторий
**Если аргументы не переданы, то создается один элемент списка со значеним '.'
*/

int			list_add(t_file	**tmp, int ac, char **av, int n)
{
	t_file	*p;

	if(ac == n)
	{
		if(!(*tmp = new_list_elem_file(".")))
			return (0);
		return (1);
	}
	if(!(*tmp = new_list_elem_file(av[n++])))
		return (0);
	while (--ac > 1)
	{
		if (!(p = new_list_elem_file(av[n++])))
			return (0);
		ft_lstadd_file(tmp, p);
	}
	return (1);
}

void		print_list(t_file *tmp)
{
	t_file	*p;

	p = tmp;
	while (p)
	{
		if (p->name[0] != '.')
		{
			ft_putstr(p->name);
			ft_putchar('\n');
			//printf("d-%d\tlink-%d\tfile-%d\n", p->is_dir, p->is_link,p->is_reg);
		}
		p = p->next;
	}
}

/*
**Очищает память выделенную под элементы списка t_file и name
*/

void 	free_list(t_file **tmp)
{
	t_file	*p;
	t_file	*d;

	p = *tmp;
	*tmp = NULL;
	while (p)
	{
		d = p;
		p = p->next;
		free(d->name);
		d->next = NULL;
		free(d);
	}
	free(*tmp);
}