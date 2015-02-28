/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:14:46 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 15:40:35 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	sub = (char *)malloc(sizeof(*s) * len + 1);
	if (len == 0)
	{
		*sub = 0;
		return (sub);
	}
	if (s)
	{
		if (sub == NULL)
			return (NULL);
		while (len != 0)
		{
			sub[i] = s[start + i];
			i++;
			len--;
		}
		sub[i] = 0;
		return (sub);
	}
	return (NULL);
}
