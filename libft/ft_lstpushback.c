/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 14:27:32 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 14:54:20 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpushback(t_list **lstinit, t_list *elem)
{
	t_list	*lst;

	lst = *lstinit;
	if (*lstinit == NULL)
		*lstinit = elem;
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = elem;
	}
}
