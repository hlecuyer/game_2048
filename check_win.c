/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:45:06 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/03/01 13:20:09 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		check_win(t_env *env, t_grid *grid)
{
	int	x;
	int	y;

	x = 0;
	while (x < env->nrows)
	{
		y = 0;
		while (y < env->ncols)
		{
			if (grid->grid[x][y].value == WIN_VALUE)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
