/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:03:22 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 14:42:23 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <ncurses.h>
# include <menu.h>
# include <stdlib.h>
# include <libft.h>
# include <signal.h>

typedef struct		s_elem
{
	int		value;
	WINDOW	*win;
}					t_elem;

typedef struct		s_grid
{
	t_elem			**grid;
	int				*free_spot;
	int				number_of_free_spot;
	int				move;
}					t_grid;

typedef struct		s_env
{
	int				nrows;
	int				ncols;
	int				trows;
	int				tcols;
	WINDOW			*win;
}					t_env;

typedef struct		s_check_signal
{
	WINDOW			*win;
	int 			trows;
	int				tcols;
}					t_check_signal;

t_grid *		init_grid(t_env * env, t_grid *grid);
void			start_game(t_env env, t_grid *grid);
void			init_ncurses(t_env *env);
void			main_loop(t_env *env, t_grid *grid);


#endif
