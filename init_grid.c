/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarmol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:26:13 by fmarmol           #+#    #+#             */
/*   Updated: 2015/03/01 14:55:36 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "game_2048.h"

t_grid	*init_grid(t_env *env, t_grid *grid)
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
	start_game(env, grid);
	return (grid);
}
