/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarmol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:55:15 by fmarmol           #+#    #+#             */
/*   Updated: 2015/03/01 13:59:34 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

void left_fusion(t_env *env, t_grid *grid)
{
	int x;
	int y;

	x = 0;
	while (x < env->nrows)
	{
		y = 0;
		while (y < env->ncols - 1)
		{
			if (grid->grid[x][y].value == grid->grid[x][y + 1].value)
			{
				grid->grid[x][y].value *= 2;
				grid->grid[x][y + 1].value = 0;
			}
			y++;
		}
		x++;
	}
	left_shift(env, grid);
}

void right_fusion(t_env *env, t_grid *grid)
{
	int x;
	int y;

	x = 0;
	while (x < env->nrows)
	{
		y = env->ncols - 1;
		while (y > 0)
		{
			if (grid->grid[x][y].value == grid->grid[x][y - 1].value)
			{
				grid->grid[x][y].value *= 2;
				grid->grid[x][y - 1].value = 0;
			}
			y--;
		}
		x++;
	}
	right_shift(env, grid);
}

void top_fusion(t_env *env, t_grid *grid)
{
	int x;
	int y;

	y = 0;
	while (y < env->ncols)
	{
		x = 0;
		while (x < env->nrows - 1)
		{
			if (grid->grid[x][y].value == grid->grid[x + 1][y].value)
			{
				grid->grid[x][y].value *= 2;
				grid->grid[x + 1][y].value = 0;
			}
			x++;
		}
		y++;
	}
	top_shift(env, grid);
}

void bottom_fusion(t_env *env, t_grid *grid)
{
	int x;
	int y;

	y = 0;
	while (y < env->ncols)
	{
		x = env->nrows - 1;
		while (x > 0)
		{
			if (grid->grid[x][y].value == grid->grid[x - 1][y].value)
			{
				grid->grid[x][y].value *= 2;
				grid->grid[x - 1][y].value = 0;
			}
			x--;
		}
		y++;
	}
	bottom_shift(env, grid);
}
