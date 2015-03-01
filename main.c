/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 09:35:55 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/03/01 15:09:26 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_2048.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	t_grid	grid;
	t_env	env;

	srand(time(0));
	init_ncurses(&env);
	if (menu(&env))
	{
		init_grid(&env, &grid);
		if (main_loop(&env, &grid) == 1)
		{
			endwin();
			free_struct(&env, &grid);
			ft_putendl("You win!!!");
		}
		else
		{
			endwin();
			free_struct(&env, &grid);
			ft_putendl("You loose!!!");
		}
	}
	else
		endwin();
	return (0);
}
