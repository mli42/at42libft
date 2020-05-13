/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:19:30 by mli               #+#    #+#             */
/*   Updated: 2020/05/13 17:02:44 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstfill(t_list *lst, t_list *new, void *(*f)(void *))
{
	while (lst)
	{
		if (!(new->next = ft_lstnew(f(lst->content))))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (new);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (!lst || !(new = ft_lstnew(f(lst->content))))
		return (NULL);
	if (!ft_lstfill(lst->next, new, f))
		ft_lstclear(&new, del);
	return (new);
}
