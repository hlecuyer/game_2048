/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:51:59 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 15:34:27 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	int		i;

	i = 0;
	map = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (map == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		map[i] = (char)f(s[i]);
		i++;
	}
	map[i] = 0;
	return (map);
}
