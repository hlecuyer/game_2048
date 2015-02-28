/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 09:35:55 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 15:54:57 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_2048.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

t_check_signal check_signal;

int main()
{
	t_grid	grid;
	t_env	env;
	int ch;

	srand(time(NULL));
	env.ncols = 4;
    env.nrows = 4;
	init_ncurses(&env);
	if (!init_grid(&env, &grid))
		return (-1);
	start_game(&env, &grid);
	printw("%d  %d  %d  %d\n%d  %d  %d  %d\n%d  %d  %d  %d\n%d  %d  %d  %d\n", grid.grid[0][0].value, grid.grid[0][1].value, grid.grid[0][2].value, grid.grid[0][3].value, grid.grid[1][0].value, grid.grid[1][1].value, grid.grid[1][2].value, grid.grid[1][3].value, grid.grid[2][0].value, grid.grid[2][1].value, grid.grid[2][2].value, grid.grid[2][3].value, grid.grid[3][0].value, grid.grid[3][1].value, grid.grid[3][2].value, grid.grid[3][3].value);
    while((ch = getch()) != KEY_F(1))
	{
		switch(ch)
		{
		case KEY_LEFT:
			leftkey(&env, &grid);
			add_rand_num(&env, &grid, 0);
			printw("left\n");
			break;
		case KEY_RIGHT:
			printw("%d  %d  %d  %d\n%d  %d  %d  %d\n%d  %d  %d  %d\n%d  %d  %d  %d\n", grid.grid[0][0].value, grid.grid[0][1].value, grid.grid[0][2].value, grid.grid[0][3].value, grid.grid[1][0].value, grid.grid[1][1].value, grid.grid[1][2].value, grid.grid[1][3].value, grid.grid[2][0].value, grid.grid[2][1].value, grid.grid[2][2].value, grid.grid[2][3].value, grid.grid[3][0].value, grid.grid[3][1].value, grid.grid[3][2].value, grid.grid[3][3].value);
			printw("right\n");
			break;
		case KEY_UP:
			printw("%d  %d  %d  %d\n%d  %d  %d  %d\n%d  %d  %d  %d\n%d  %d  %d  %d\n", grid.grid[0][0].value, grid.grid[0][1].value, grid.grid[0][2].value, grid.grid[0][3].value, grid.grid[1][0].value, grid.grid[1][1].value, grid.grid[1][2].value, grid.grid[1][3].value, grid.grid[2][0].value, grid.grid[2][1].value, grid.grid[2][2].value, grid.grid[2][3].value, grid.grid[3][0].value, grid.grid[3][1].value, grid.grid[3][2].value, grid.grid[3][3].value);
			printw("up\n");
			break;
		case KEY_DOWN:
			printw("%d  %d  %d  %d\n%d  %d  %d  %d\n%d  %d  %d  %d\n%d  %d  %d  %d\n", grid.grid[0][0].value, grid.grid[0][1].value, grid.grid[0][2].value, grid.grid[0][3].value, grid.grid[1][0].value, grid.grid[1][1].value, grid.grid[1][2].value, grid.grid[1][3].value, grid.grid[2][0].value, grid.grid[2][1].value, grid.grid[2][2].value, grid.grid[2][3].value, grid.grid[3][0].value, grid.grid[3][1].value, grid.grid[3][2].value, grid.grid[3][3].value);
			printw("down\n");
			break;
		}
	}
	ft_putstr("Ok c'est cool\n");


	return 0;
}
