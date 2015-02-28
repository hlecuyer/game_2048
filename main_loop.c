/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarmol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:39:16 by fmarmol           #+#    #+#             */
/*   Updated: 2015/02/28 16:03:07 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

extern int flag_signal;

static void resize_windows(t_env *env, t_grid *grid)
{
	int	i;
	int	j;
	int	width;
	int	height;
	WINDOW *win;

	width = env->tcols/env->ncols;
	height = env->trows/env->nrows;
	i = 0;
	wprintw(env->win, "%d %d %d %d\n", env->trows, env->tcols, width, height);
	while (i < env->nrows)
	{
		j = 0;
		while (j < env->ncols)
		{
			delwin((grid->grid[i][j]).win);
			win = newwin(height, width, i*height, j*width);
			(grid->grid[i][j]).win = win;
			j++;
		}
		i++;
	}
	flag_signal = 0;
}

static void handle_sigwinch(int i)
{
	flag_signal = 1;
	i++;
}

static void refresh_windows(t_env * env, t_grid * grid){
	int		i;
	int		j;
	int		x;
	int		y;
	int width;
	int height;
	WINDOW	*win;


	width = env->tcols/env->ncols;
	height = env->trows/env->nrows;
	i = 0;
	while (i < env->nrows)
	{
		j = 0;
		while (j < env->ncols)
		{
			if (grid->grid[i][j].win != 0)
				delwin((grid->grid[i][j]).win);
			win = newwin(height, width, i*height, j*width);
			(grid->grid[i][j]).win = win;
			wbkgd(win, COLOR_PAIR(grid->grid[i][j].value + 1));
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
	int x;
	int y;

	while((ch=getch() != 27))
	{
		getmaxyx(env->win, y, x);
		env->trows = y;
		env->tcols = x;
		refresh_windows(env, grid);
		wrefresh(env->win);
	}
}
