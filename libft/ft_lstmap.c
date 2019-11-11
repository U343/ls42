/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:58:10 by wanton            #+#    #+#             */
/*   Updated: 2019/09/17 12:49:35 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;
	t_list	*new_head;

	new_head = (t_list *)NULL;
	if (lst && f)
	{
		head = lst;
		if (!(new = f(head)))
			return ((t_list *)NULL);
		new_head = new;
		head = head->next;
		while (head)
		{
			if (!(new->next = f(head)))
			{
				ft_lstdel(&new_head, &ft_del);
				return ((t_list *)NULL);
			}
			new = new->next;
			head = head->next;
		}
	}
	return (new_head);
}
