/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:01:24 by wanton            #+#    #+#             */
/*   Updated: 2019/11/29 11:30:41 by wanton           ###   ########.fr       */
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
# include <sys/ioctl.h>

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
	int 			len_name;
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
int					dcount_list(t_file *head);
int					main_print(t_file **head, t_file **tmp, int flag);
void				free_list(t_file **tmp);
void				move_dir(t_file	**lst);
void				ft_lstadd_file(t_file **alst, t_file *new);
void				sort_list(t_file **lst, __uint16_t flag);
void				list_elem_info(t_file *tmp, struct stat buf);
void				print_list(t_file *tmp, __uint16_t flag, int maxlen, int l);
t_file				*new_list_elem_file(char *s);
t_file				*ft_take_elem(t_file *head, int n);

void				test_print(t_file	*tmp); // не забыть удалить

/*
**Functions for open and read directory
*/

int					open_dir(char *adr, t_file **head, __uint16_t flag, int *l);
int					more_info(t_file *tmp, __uint16_t flag);

#endif
