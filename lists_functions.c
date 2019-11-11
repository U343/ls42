/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:16:53 by wanton            #+#    #+#             */
/*   Updated: 2019/11/11 12:49:06 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Создает новый элемент списка
*/

t_file		*new_list_elem(char *s)
{
	t_file	*new;

	if(!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if(!(new->name = ft_strdup(s)))
		return (NULL);
	new->type = '*';
	new->error = 0;
	new->next = NULL;
	return (new);
}

/*
**Добавляет элементы в конец списка tmp
*/

static	void	ft_listadd(t_file **alst, t_file *new)
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

int 		list_add(t_file **tmp, int ac, char **av)
{
	t_file *p;
	int		i;

	i = 1;
	if(ac == 1)
	{
		if(!(*tmp = new_list_elem(".")))
			return (0);
		return (1);
	}
	if(!(*tmp = new_list_elem(av[i++])))
		return (0);
	while (--ac > 1)
	{
		if (!(p = new_list_elem(av[i++])))
			return (0);
		ft_listadd(tmp, p);
	}
	return (1);
}

void		print_list(t_file *tmp)
{
	t_file	*p;

	p = tmp;
	while (p)
	{
		ft_putstr(p->name);
		ft_putchar('\n');
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
	while (p)
	{
		d = p;
		p = p->next;
		free(d->name);
		free(d);
	}
	free(tmp);
}