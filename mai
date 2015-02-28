/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 09:35:55 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 12:46:32 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <game_2048.h>

t_check_signal check_signal;

int main()
{
	//t_grid	grid;
	t_env	env;
	int		c;

	init_ncurses(&env);
	c = getch();
	endwin();
	printf("key pressed: %d\n", c);
	printf("term rows = %d, term cols = %d\n", env.ntrows, env.ncols);
	ft_putstr("Ok c'est cool\n");
	return 0;
}
