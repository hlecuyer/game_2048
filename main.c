/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 09:35:55 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 14:45:46 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <game_2048.h>

//t_check_signal check_signal;
int flag_signal;

int main()
{
	t_grid	grid;
	t_env	env;

	flag_signal = 0;
	init_ncurses(&env);
	init_grid(&env, &grid);
	main_loop(&env, &grid);
	endwin();
	printf("term rows = %d, term cols = %d\n", env.trows, env.tcols);
	return 0;
}
