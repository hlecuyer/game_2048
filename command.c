/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:49:09 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/03/01 11:37:49 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		left_shift(t_env *env, t_grid *grid)
{
	int i;
	int y;
	int	x;

	x = 0;
	while (x < env->nrows)
	{
		i = env->ncols + 1;
		while (i-- != 0)
		{
			y = 0;
			while (y < env->ncols - 1)
			{
				if (grid->grid[x][y].value == 0)
				{
					grid->grid[x][y].value = grid->grid[x][y + 1].value;
					env->left_flag = env->left_flag > 0
					|| grid->grid[x][y].value > 0 ? 1 : 0;
					grid->grid[x][y + 1].value = 0;
				}
				y++;
			}
		}
		x++;
	}
}

void		right_shift(t_env *env, t_grid *grid)
{
	int i;
	int y;
	int	x;

	x = 0;
	while (x < env->nrows)
	{
		i = env->ncols + 1;
		while (i-- != 0)
		{
			y = env->ncols - 1;
			while (y > 0)
			{
				if (grid->grid[x][y].value == 0)
				{
					grid->grid[x][y].value = grid->grid[x][y - 1].value;
					env->right_flag = env->right_flag > 0
					|| grid->grid[x][y].value > 0 ? 1 : 0;
					grid->grid[x][y - 1].value = 0;
				}
				y--;
			}
		}
		x++;
	}
}

void		top_shift(t_env *env, t_grid *grid)
{
	int i;
	int y;
	int	x;

	y = 0;
	while (y < env->ncols)
	{
		i = env->nrows + 1;
		while (i-- != 0)
		{
			x = 0;
			while (x < env->nrows - 1)
			{
				if (grid->grid[x][y].value == 0)
				{
					grid->grid[x][y].value = grid->grid[x + 1][y].value;
					env->top_flag = env->top_flag > 0
					|| grid->grid[x][y].value > 0 ? 1 : 0;
					grid->grid[x + 1][y].value = 0;
				}
				x++;
			}
		}
		y++;
	}
}

void		bottom_shift(t_env *env, t_grid *grid)
{
	int i;
	int y;
	int	x;

	y = 0;
	while (y < env->ncols)
	{
		i = env->nrows + 1;
		while (i-- != 0)
		{
			x = env->nrows - 1;
			while (x > 0)
			{
				if (grid->grid[x][y].value == 0)
				{
					grid->grid[x][y].value = grid->grid[x - 1][y].value;
					env->bottom_flag = env->bottom_flag > 0
					|| grid->grid[x][y].value > 0 ? 1 : 0;
					grid->grid[x - 1][y].value = 0;
				}
				x--;
			}
		}
		y++;
	}
}
