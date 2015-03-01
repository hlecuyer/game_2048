/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:13:56 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/03/01 15:43:50 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		next_turn(t_env *env, t_grid *grid)
{
	if (env->left_flag == 1 || env->right_flag == 1
		|| env->top_flag == 1 || env->bottom_flag == 1)
	{
		add_rand_num(env, grid, rand() % 2);
		env->left_flag = 0;
		env->right_flag = 0;
		env->top_flag = 0;
		env->bottom_flag = 0;
	}
}

void		reset_win(t_env *env, t_grid *grid)
{
	int	x;
	int	y;

	getmaxyx(env->win, y, x);
	env->trows = y;
	env->tcols = x;
	refresh_windows(env, grid);
	wrefresh(env->win);
}
