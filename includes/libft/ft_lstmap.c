/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:39:29 by cparras           #+#    #+#             */
/*   Updated: 2023/06/05 16:17:45 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (!lst)
		return (0);
	new = ft_lstnew((*f)(lst->d));
	if (!new)
		return (0);
	first = new;
	lst = lst->nt;
	while (lst)
	{
		new->nt = ft_lstnew((*f)(lst->d));
		if (!new->d)
		{
			ft_lstclear(&first, (*del));
			return (0);
		}
	new = new->nt;
	lst = lst->nt;
	}
	return (first);
}
