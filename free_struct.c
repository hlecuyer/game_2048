/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:01:46 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/03/01 13:34:20 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		free_struct(t_env *env, t_grid *grid)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < env->nrows)
	{
		y = 0;
		while (y < env->ncols)
		{
			delwin(grid->grid[x][y].win);
			y++;
		}
		free(grid->grid[x]);
		x++;
	}
	free(grid->grid);
	free(grid->free_spot);
	delwin(env->win);
}
