# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wanton <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 12:43:07 by wanton            #+#    #+#              #
#    Updated: 2019/11/25 12:30:16 by wanton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror 

SRC = ft_putspace.c ft_strldub.c ft_sort_int.c ft_min.c ft_max.c ft_del.c ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_strlen.c ft_strlcat.c ft_bzero.c ft_memdel.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_putchar.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putstr.c ft_putendl_fd.c ft_putnbr_fd.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memmove.c ft_memalloc.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strstr.c ft_strnew.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strsplit.c ft_strcmp.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_isspace.c ft_atoi.c ft_memcmp.c ft_strequ.c ft_strnequ.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.c.o:
	@gcc $(FLAG) -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
