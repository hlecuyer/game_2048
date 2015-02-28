/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:36:58 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/26 17:07:29 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count_dst;
	size_t	count_src;
	size_t	len;

	len = ft_strlen(dst) + ft_strlen(src);
	if ((int)size == 0)
		return (ft_strlen(src));
	count_dst = 0;
	count_src = 0;
	while (dst[count_dst] != '\0')
		count_dst++;
	if (count_dst > size)
		return (size + ft_strlen(src));
	while (src[count_src] != '\0' && count_dst + count_src < size - 1)
	{
		dst[count_dst + count_src] = src[count_src];
		count_src++;
	}
	dst[count_dst + count_src] = '\0';
	return (len);
}
