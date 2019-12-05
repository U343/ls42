/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:55:00 by wanton            #+#    #+#             */
/*   Updated: 2019/11/29 11:44:55 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Определяет флаги, переданные как аргумент
**флаги хранятся в flag в виде 0 и 1
*/

int		check_flag(__uint16_t *flag, char elem)
{
	if (elem == 'l')
		*flag = *flag | (1 << 0);
	else if (elem == 'R')
		*flag = *flag | (1 << 1);
	else if (elem == 'a')
		*flag = *flag | (1 << 2);
	else if (elem == 'r')
		*flag = *flag | (1 << 3);
	else if (elem == 't')
		*flag = *flag | (1 << 4);
	else
	{
		ft_putstr("usage\n");
		return (-1);
	}
	return (1);
}

/*
**Пробегает по аргументам до тех пор пока идут флаги или пока они не кончатся
**Нужна для того чтобы пропарсить флаги
*/

int		flag_pars(__uint16_t *flag, int ac, char **av)
{
	int i;
	int count;

	i = 1;
	if (ac == 1)
		return (1);
	while (--ac != 0 && av[i][0] == '-')
	{
		count = 1;
		if (av[i][count] == '\0')
			return (i);
		while (av[i][count] != '\0')
		{
			if (check_flag(flag, av[i][count]) == -1)
				return (-1);
			count++;
		}
		i++;
	}
	return (i);
}

int		main(int ac, char **av)
{
	t_file		*tmp;
	t_file		*head;
	__uint16_t	flag;
	int 		n;

	flag = 0;
	n = flag_pars(&flag, ac, av); // Получили индекс аргумента с которого начинаются файлы и папки
	if (ac - n != 0) // проверяем есть ли еще аргументы кроме флага
		flag = flag | (1 << 5); // ставим флаг MD
	/*if (!(list_add(&tmp, ac, av, n))) // формируем массив аргументов
	{
		free_list(&tmp); // если ошибка, очищаем
		return (0);
	}
	if ((flag & LS_MD) != 0) // проверяем кол-во arg если больше 1 - сорт
		sort_list(&tmp, flag);*/
	if (!(main_print(&head, &tmp, flag)))
		return (0);
	free_list(&head);
	free_list(&tmp);
	return (0);
}
