/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:17:52 by hlecuyer          #+#    #+#             */
/*   Updated: 2013/12/01 18:35:16 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (lstnew == 0)
		return (NULL);
	if (content == NULL)
	{
		lstnew->content_size = 0;
		lstnew->content = NULL;
	}
	else
	{
		lstnew->content = (void *)malloc(sizeof(content) * content_size);
		if (lstnew->content == NULL)
			return (NULL);
		ft_memcpy(lstnew->content, content, content_size);
		lstnew->content_size = content_size;
	}
	lstnew->next = NULL;
	return (lstnew);
}
