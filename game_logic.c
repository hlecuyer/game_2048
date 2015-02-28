/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:36:34 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 16:41:04 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_2048.h"


void	check_empty_spot(t_env *env, t_grid *grid)
{
	int	i;
	int y;

	i = 0;
	y = 0;
	ft_bzero(grid->free_spot, sizeof(int) * env->ncols * env->nrows);
	while (i < (env->ncols * env->nrows))
	{
		if (grid->grid[i / env->nrows][i % env->ncols].value == 0)
		{
			grid->free_spot[y] = i;
			y++;
		}
		i++;
	}
	grid->number_of_free_spot = y;
}

void	add_rand_num(t_env *env, t_grid *grid, int num)
{
	int pos;

	if (grid->number_of_free_spot == 0)
		return ;
	pos = 0;
	check_empty_spot(env, grid);
	pos = rand() % grid->number_of_free_spot;
	pos = grid->free_spot[pos];
	if (!num)
		grid->grid[pos / env->nrows][pos % env->ncols].value = 2;
	else
		grid->grid[pos / env->nrows][pos % env->ncols].value = 4;
}


void	start_game(t_env *env, t_grid *grid)
{
	add_rand_num(env, grid, 0);
	add_rand_num(env, grid, 0);
}
