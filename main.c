/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 09:35:55 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/03/01 12:58:50 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_2048.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/stat.h> 
#include <fcntl.h>

int fd;

int main()
{
	fd = open("./error_log",O_WRONLY|O_CREAT, 0666);
	t_grid	grid;
	t_env	env;
	srand(time(0));
	init_ncurses(&env);
	init_grid(&env, &grid);
	if (main_loop(&env, &grid) == 1)
	{
		endwin();
		ft_putendl("You win!!!");
	}
	else
	{
		endwin();
		ft_putendl("You looser!!!");
	}
	return 0;
}
