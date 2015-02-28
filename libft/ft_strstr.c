/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:17:08 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 15:45:00 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str2 == str1)
		return ((char *)str1);
	while (str1[i] != 0)
	{
		while (str1[i + j] == str2[j] && str1[i + j] != 0)
			j++;
		if (str2[j] == 0)
			return ((char *)&str1[i]);
		j = 0;
		i++;
	}
	return (0);
}
