/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:26:16 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 15:19:11 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c2;
	unsigned int	i;

	if ((int)n == 0)
		return (NULL);
	c2 = (unsigned char)c;
	if (s)
	{
		ptr = (unsigned char *)s;
		i = 0;
		while (ptr[i] != c2)
		{
			if (i == n - 1)
				return (NULL);
			i++;
		}
		return ((void *)&ptr[i]);
	}
	return (NULL);
}
