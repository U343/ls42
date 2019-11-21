/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:58:14 by wanton            #+#    #+#             */
/*   Updated: 2019/11/20 10:34:57 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*int 	main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*res;
	struct stat		buf;
	int 			p;


	if (ac == 1)
	{
		if (!(dir = opendir(".")))
		{
			ft_putstr("error open directory '.'\n");
			return (0);
		}
	}
	else
	{
		if (!(dir = opendir(av[1])))
		{
			ft_putstr("error open directory\n");
			ft_putstr(av[1]);
			ft_putchar('\n');
			return (0);
		}
	}
	while ((res = readdir(dir)))
	{
		if ((p = stat(res->d_name, &buf)) != 0)
		{
			ft_putstr("error stat\n");
			return (0);
		}
		if (res->d_name[0] != '.')
		{
			ft_putstr(res->d_name);
			ft_putstr("\t\t");
			ft_putnbr(S_ISDIR(buf.st_mode));
			*//*ft_putstr(time);*//*
			ft_putchar('\n');
		}
	}
	ft_putstr("-----------\n");
	ft_putstr(getenv("COLUMNS"));
	closedir(dir);
	return (0);
}*/
