/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:25:58 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 15:38:57 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*strnew;
	unsigned int	i;

	i = 0;
	strnew = (char *)malloc(sizeof(char) * size);
	if (strnew == NULL)
		return (NULL);
	else
	{
		while (i <= size)
		{
			strnew[i] = 0;
			i++;
		}
	}
	return (strnew);
}
