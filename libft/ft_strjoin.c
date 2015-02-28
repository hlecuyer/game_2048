/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:24:18 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 15:33:45 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		i;
	int		j;

	if (s1 && s2)
	{
		i = (int)ft_strlen(s1);
		j = 0;
		strjoin = (char *)malloc(sizeof(char) * (i + (int)ft_strlen(s2) + 1));
		if (strjoin == NULL)
			return (NULL);
		strjoin = ft_strcpy(strjoin, s1);
		while (s2[j] != 0)
		{
			strjoin[i + j] = s2[j];
			j++;
		}
		strjoin[i + j] = 0;
		return (strjoin);
	}
	return (NULL);
}
