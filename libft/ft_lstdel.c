/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:21:19 by hlecuyer          #+#    #+#             */
/*   Updated: 2013/12/01 19:55:23 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	ptr = NULL;
	while ((*alst)->next != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		ptr = (*alst)->next;
		if (*alst != NULL)
			free(*alst);
		*alst = ptr;
	}
	del((*alst)->content, (*alst)->content_size);
	if (*alst != NULL)
		free(*alst);
	*alst = NULL;
}
