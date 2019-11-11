/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:34:00 by wanton            #+#    #+#             */
/*   Updated: 2019/09/16 13:50:07 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*head;
	t_list	*tmp;

	if (del)
	{
		head = *alst;
		while (head != NULL)
		{
			tmp = head;
			head = head->next;
			tmp->next = NULL;
			ft_lstdelone(&tmp, del);
		}
		*alst = NULL;
	}
}
