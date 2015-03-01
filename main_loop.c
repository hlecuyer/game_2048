/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarmol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:39:16 by fmarmol           #+#    #+#             */
/*   Updated: 2015/03/01 12:53:18 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

extern int fd;

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

	while((ch=getch()) != 27)
	{
		switch(ch)
		{
		case KEY_LEFT:
			left_shift(env, grid);
			left_fusion(env,grid);
			if (env->left_flag == 0)
			{
				env->left_flag = -1;
			}
			break;
		case KEY_RIGHT:
			right_shift(env,grid);
			right_fusion(env,grid);
			if (env->right_flag == 0)
			{
				env->right_flag = -1;
			}
			break;
		case KEY_UP:
			top_shift(env,grid);
			top_fusion(env,grid);
			if (env->top_flag == 0)
			{
				env->top_flag = -1;
			}
			break;
		case KEY_DOWN:
			bottom_shift(env,grid);
			bottom_fusion(env,grid);
			if (env->bottom_flag == 0)
			{
				env->bottom_flag = -1;
			}
			break;
		}
		//ft_putendl_fd(ft_itoa(env->left_flag),fd);
		//ft_putendl_fd(ft_itoa(env->right_flag),fd);
		//ft_putendl_fd(ft_itoa(env->top_flag),fd);
		//ft_putendl_fd(ft_itoa(env->bottom_flag),fd);
		//ft_putendl_fd("",fd);
		if (env->left_flag == 1 || env->right_flag == 1 || env->top_flag == 1 || env->bottom_flag == 1){
			add_rand_num(env, grid, rand()%2);
			env->left_flag = 0;
			env->right_flag = 0;
			env->top_flag = 0;
			env->bottom_flag = 0;
		}
		if (env->left_flag == -1 && env->right_flag == -1 && env->top_flag == -1  && env->bottom_flag == -1)
			break;
		getmaxyx(env->win, y, x);
		env->trows = y;
		env->tcols = x;
		refresh_windows(env, grid);
		wrefresh(env->win);
	}
}
