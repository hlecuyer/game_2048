/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 09:35:55 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/03/01 16:00:00 by fmarmol          ###   ########.fr       */
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
	int		res;

	srand(time(0));
	init_ncurses(&env);
	if (menu(&env))
	{
		init_grid(&env, &grid);
		res = main_loop(&env, &grid);
		free_struct(&env, &grid);
		endwin();
		if (res == 1)
			ft_putendl("You win!!!");
		else if (res == -1)
			ft_putendl("You loose!!!");
		else
			ft_putendl("Thank you for playing!!!");
	}
	else
	{
		endwin();
		ft_putendl("GoodBye!!");
	}
	return (0);
}
