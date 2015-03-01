/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:00:04 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/03/01 15:30:13 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		key_left(t_env *env, t_grid *grid)
{
	left_shift(env, grid);
	left_fusion(env,grid);
	if (env->left_flag == 0)
	{
		env->left_flag = -1;
	}
}

void		key_right(t_env *env, t_grid *grid)
{
	right_shift(env,grid);
	right_fusion(env,grid);
	if (env->right_flag == 0)
	{
		env->right_flag = -1;
	}
}

void		key_up(t_env *env, t_grid *grid)
{
	top_shift(env,grid);
	top_fusion(env,grid);
	if (env->top_flag == 0)
	{
		env->top_flag = -1;
	}
}

void		key_down(t_env *env, t_grid *grid)
{
	bottom_shift(env,grid);
	bottom_fusion(env,grid);
	if (env->bottom_flag == 0)
	{
		env->bottom_flag = -1;
	}
}
