/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:21:44 by hlecuyer          #+#    #+#             */
/*   Updated: 2013/11/26 20:42:14 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned int	i;
	unsigned char	c2;

	c2 = (unsigned char)c;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		if (ptr2[i] == c2)
			return (s1 + (i + 1));
		i++;
	}
	return (NULL);
}
