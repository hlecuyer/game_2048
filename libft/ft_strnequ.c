/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:55:00 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 15:37:07 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n < 1)
		return (1);
	if (s1 && s2)
	{
		while (*s1 == *s2 && n != 0)
		{
			if (*s1 == 0)
				return (1);
			s1++;
			s2++;
			n--;
		}
		if (n != 0)
			return (0);
		else
			return (1);
	}
	return (0);
}
