/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:41:45 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 13:53:24 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "game_2048.h"

static void init_win(t_env *env, t_grid *grid)
{
	int	i;
	int	j;
	int	width;
	int	height;
	WINDOW *win;

	width = env->tcols/env->ncols;
	height = env->trows/env->nrows;
	i = 0;
	while (i < env->nrows)
	{
		j = 0;
		while (j < env->ncols)
		{
			win = newwin(height, width, i*height, j*width);
			(grid->grid[i][j]).win = win;
			box(win, 0 ,0);
			j++;
		}
		i++;
	}
}

t_grid *		init_grid(t_env * env, t_grid *grid)
{
	int		i;

	i = 0;
	grid->grid = (t_elem **)malloc(sizeof(t_elem *) * env->nrows);
	if (grid->grid == NULL)
		return (NULL);
	while (i < env->nrows)
	{
		grid->grid[i] = (t_elem *)malloc(sizeof(t_elem) * env->ncols);
		if (grid->grid[i] == NULL)
			return (NULL);
		ft_bzero(grid->grid[i], sizeof(t_elem) * env->ncols);
		i++;
	}
	grid->free_spot = (int *)malloc(sizeof(int) * (env->ncols * env->nrows));
	if (grid->free_spot == NULL)
		return (NULL);
	init_win(env, grid);
	//refresh();
	return (grid);
}
