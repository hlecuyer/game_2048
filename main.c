/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 09:35:55 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 16:26:11 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_2048.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/stat.h> 
#include <fcntl.h>

int main()
{
	int fd;

	fd = open("./error_log",O_WRONLY|O_CREAT, 0666);
	t_grid	grid;
	t_env	env;
	srand(time(0));
	init_ncurses(&env);
	init_grid(&env, &grid);
	main_loop(&env, &grid);
	endwin();
	return 0;
}
