/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:36:34 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 15:52:08 by hlecuyer         ###   ########.fr       */
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
	printw("anant =>%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n",grid->free_spot[0],grid->free_spot[1],grid->free_spot[2],grid->free_spot[3],grid->free_spot[4],grid->free_spot[5],grid->free_spot[6],grid->free_spot[7],grid->free_spot[8],grid->free_spot[9],grid->free_spot[10],grid->free_spot[11],grid->free_spot[12],grid->free_spot[13],grid->free_spot[14], grid->free_spot[15],grid->free_spot[16]);
	while (i < (env->ncols * env->nrows))
	{
		if (grid->grid[i / env->nrows][i % env->ncols].value == 0)
		{
			grid->free_spot[y] = i;
			y++;
		}
		i++;
	}
	printw("apres => %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n",grid->free_spot[0],grid->free_spot[1],grid->free_spot[2],grid->free_spot[3],grid->free_spot[4],grid->free_spot[5],grid->free_spot[6],grid->free_spot[7],grid->free_spot[8],grid->free_spot[9],grid->free_spot[10],grid->free_spot[11],grid->free_spot[12],grid->free_spot[13],grid->free_spot[14], grid->free_spot[15],grid->free_spot[16]);
	printw("%d =  y \n", y);
	printw("%d  %d  %d  %d\n%d  %d  %d  %d\n%d  %d  %d  %d\n%d  %d  %d  %d\n", grid->grid[0][0].value, grid->grid[0][1].value, grid->grid[0][2].value, grid->grid[0][3].value, grid->grid[1][0].value, grid->grid[1][1].value, grid->grid[1][2].value, grid->grid[1][3].value, grid->grid[2][0].value, grid->grid[2][1].value, grid->grid[2][2].value, grid->grid[2][3].value, grid->grid[3][0].value, grid->grid[3][1].value, grid->grid[3][2].value, grid->grid[3][3].value);

	grid->number_of_free_spot = y;
}

void	add_rand_num(t_env *env, t_grid *grid, int num)
{
	int pos;

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
