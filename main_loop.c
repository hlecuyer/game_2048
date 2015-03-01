/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarmol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:39:16 by fmarmol           #+#    #+#             */
/*   Updated: 2015/03/01 15:54:15 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

static WINDOW	*init_win(t_env *env, int i, int j)
{
	int		width;
	int		height;

	width = env->tcols / env->ncols;
	height = env->trows / env->nrows;
	return (newwin(height, width, i * height, j * width));
}

void			refresh_windows(t_env *env, t_grid *grid)
{
	int		i;
	int		j;
	int		x;
	int		y;
	WINDOW	*win;

	i = 0;
	while (i < env->nrows)
	{
		j = 0;
		while (j < env->ncols)
		{
			if (grid->grid[i][j].win != 0)
				delwin((grid->grid[i][j]).win);
			win = init_win(env, i, j);
			(grid->grid[i][j]).win = win;
			wbkgd(win, COLOR_PAIR((grid->grid[i][j].value + 1) % 126));
			getmaxyx(win, y, x);
			mvwprintw(win, y / 2, x / 2, ft_itoa(grid->grid[i][j].value));
			wrefresh(win);
			j++;
		}
		i++;
	}
}

int				main_loop(t_env *env, t_grid *grid)
{
	int		ch;

	while ((ch = getch()) != 27)
	{
		if (check_win(env, grid))
			return (1);
		if (ch == KEY_LEFT)
			key_left(env, grid);
		if (ch == KEY_RIGHT)
			key_right(env, grid);
		if (ch == KEY_UP)
			key_up(env, grid);
		if (ch == KEY_DOWN)
			key_down(env, grid);
		next_turn(env, grid);
		if (env->left_flag == -1 && env->right_flag == -1
			&& env->top_flag == -1 && env->bottom_flag == -1)
			return (-1);
		reset_win(env, grid);
	}
	return (0);
}
