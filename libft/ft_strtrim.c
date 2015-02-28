/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:01:05 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/01/30 15:45:27 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_count(char const *s, int *i, int *j)
{
	int	begin;
	int end;

	begin = *i;
	end = *j;
	while (s[begin] == ' ' || s[begin] == '\t' || s[begin] == '\n')
		begin++;
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	*i = begin;
	*j = end;
}

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	ft_count(s, &i, &j);
	if (j - i < -1)
		j = i - 1;
	trim = (char *)malloc(sizeof(char) * (j - i + 2));
	if (trim == NULL)
		return (NULL);
	while (i <= j)
	{
		trim[k] = s[i];
		i++;
		k++;
	}
	trim[k] = 0;
	return (trim);
}
