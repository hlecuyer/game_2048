/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:27:02 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 15:18:12 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newmap;
	t_list	*newelem;

	newmap = NULL;
	while (lst != NULL)
	{
		newelem = ft_lstnew(lst->content, lst->content_size);
		if (!newelem)
			return (NULL);
		ft_lstpushback(&newmap, f(newelem));
		lst = lst->next;
	}
	return (newmap);
}
