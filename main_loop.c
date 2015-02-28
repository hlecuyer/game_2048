/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarmol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:39:16 by fmarmol           #+#    #+#             */
/*   Updated: 2015/02/28 14:09:35 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

static void refresh_windows(t_env * env, t_grid * grid){
	int		i;
	int		j;
	WINDOW	*win;
	int		x;
	int		y;

	i = 0;
	while (i < env->nrows)
	{
		j = 0;
		while (j < env->ncols)
		{
			win = (grid->grid[i][j].win);
			getmaxyx(win, y, x);
			mvwprintw(win, y/2, x/2, (const char *)ft_itoa(grid->grid[i][j].value));
			wrefresh(win);
			j++;
		}
		i++;
	}
}

void main_loop(t_env *env, t_grid *grid)
{
	int ch;

	while((ch=getch() != 27))
	{
		refresh_windows(env, grid);
		wrefresh(env->win);
	}
}
