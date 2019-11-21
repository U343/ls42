/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:01:24 by wanton            #+#    #+#             */
/*   Updated: 2019/11/21 12:51:37 by wanton           ###   ########.fr       */
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
# include <errno.h>

# include "libft/libft.h"

/*
**-------------------------------Constants--------------------------------------
**LS_UR обозначает флаг R; LS_R - флаг r
**LS_MD флаг, который показывает что есть хотябы один аргумент помимо флага
*/

# define LS_L (1<<0)
# define LS_UR (1<<1)
# define LS_A (1<<2)
# define LS_R (1<<3)
# define LS_T (1<<4)
# define LS_MD (1<<5)

/*
**--------------------------------Structs---------------------------------------
*/

typedef struct		s_file
{
	char			*name;
	char			type;
	int				error;
	int 			is_dir;
	int 			is_link;
	int 			is_reg;

	struct s_file	*next;
}					t_file;

/*
**----------------------------Function headers----------------------------------
**Functions for list t_file:
*/

int					list_add(t_file **tmp, int ac, char **av, int n);
void				free_list(t_file **tmp);
void				ft_lstadd_file(t_file **alst, t_file *new);
t_file				*new_list_elem_file(char *s);
t_file				*new_list_elem_file2(char *s, struct stat buf);
t_file				*sort_list(t_file *lst);

void				print_list(t_file *tmp); // не забыть удалить

/*
**Functions for open and read directory
*/

int					open_dir(char *adr, t_file **head);

#endif
