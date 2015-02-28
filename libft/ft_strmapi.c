/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:01:01 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 15:34:59 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		map = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
		if (map == NULL)
			return (NULL);
		while (s[i] != 0)
		{
			map[i] = f(i, s[i]);
			i++;
		}
		map[i] = 0;
		return (map);
	}
	return (NULL);
}
