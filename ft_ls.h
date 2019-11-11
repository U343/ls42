/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:01:24 by wanton            #+#    #+#             */
/*   Updated: 2019/11/11 12:54:23 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
**-------------------------------Libraries--------------------------------------
*/
# include <stdio.h> //не забыть удалить
# include <dirent.h>
# include <time.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

/*
**-------------------------------Constants--------------------------------------
*/

# define BUFF_SIZE 0;

/*
**--------------------------------Structs---------------------------------------
*/

typedef struct		s_file
{
	char			*name;
	char			type;
	int				error;
	struct s_file	*next;
}					t_file;

/*
**----------------------------Function headers----------------------------------
**Functions for list t_file:
*/

int		list_add(t_file **tmp, int ac, char **av);
void	free_list(t_file **tmp);
void	sort_list(t_file **tmp);

void	print_list(t_file *tmp); // не забыть удалить

/*
**Functions for open and read directory
*/

int		open_dir(char *adr);

#endif
