/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:45:06 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/03/01 12:56:30 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		check_win(t_env *env, t_grid *grid)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < env->ncols)
	{
		while (y < env->nrows)
		{
			if (grid->grid[x][y].value == WIN_VALUE)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
