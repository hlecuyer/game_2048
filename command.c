/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:49:09 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 16:48:58 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"


int			check_end(t_env *env, t_elem *e, int pos)
{
	while (pos < env->ncols)
	{
		if (e[pos].value == 0)
			pos++;
		else
			return (0);
	}
	return (1);
}

void		left_shift(t_env *env, t_grid *grid)
{
	int i;
	int y;
	int	x;

	x = 0;
	while (x < env->nrows)
	{
		i = env->ncols;
		while (i != 0)
		{
			y = 0;
			while (y < env->ncols - 1)
			{
				if (grid->grid[x][y].value == 0)
				{
					grid->grid[x][y].value = grid->grid[x][y + 1].value;
					grid->grid[x][y + 1].value = 0;
				}
				y++;
			}
			i--;
		}
		x++;
	}
}

// void		leftscreen(t_env *env, t_elem  *e)
// {
// 	int	i;

// 	i = 0;
// 	while (i < env->ncols - 1)
// 	{
// 		if (e[i].value == 0 && !check_end(env, e, i))
// 			left_shift(env, e);
// 		i++;
// 	}
// }


// void		leftfusion(t_env *env, t_elem  *e)
// {
// 	int	i;

// 	i = 0;
// 	while (i < env->ncols - 1)
// 	{
// 		if (e[i].value != 0 && e[i].value ==  e[i + 1].value)
// 		{
// 			e[i].value = e[i].value + e[i + 1].value;
// 			e[i + 1].value = 0;
// 			if (i + 1  != env->ncols)
// 				left_shift(env, e);
// 		}
// 		i++;
// 	}
// }

// void		leftkey(t_env * env, t_grid * grid)
// {
// 	int i;

// 	i = 0;
// 	grid->move = KEY_LEFT;
// 	while (i < env->nrows)
// 	{
// //		leftscreen(env, grid->grid[i]);
// //		leftfusion(env, grid->grid[i]);
// 		i++;
// 	}
// }
