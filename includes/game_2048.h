/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:03:22 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/03/01 10:46:23 by fmarmol          ###   ########.fr       */
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
	//int				move;
}					t_grid;

typedef struct		s_env
{
	int				nrows;
	int				ncols;
	int				trows;
	int				tcols;
	WINDOW			*win;
	int				left_flag;
	int				right_flag;
	int				top_flag;
	int				bottom_flag;
}					t_env;

t_grid *        init_grid(t_env *env, t_grid *grid);
void            start_game(t_env *env, t_grid *grid);
void			init_ncurses(t_env *env);
void			leftkey(t_env * env, t_grid * grid);
void			add_rand_num(t_env *env, t_grid *grid, int num);
void			main_loop(t_env *env, t_grid *grid);
void			left_shift(t_env *env, t_grid *grid);
void			left_fusion(t_env *env, t_grid *grid);
void			right_shift(t_env *env, t_grid *grid);
void			right_fusion(t_env *env, t_grid *grid);
void			top_shift(t_env *env, t_grid *grid);
void			top_fusion(t_env *env, t_grid *grid);
void			bottom_shift(t_env *env, t_grid *grid);
void			bottom_fusion(t_env *env, t_grid *grid);
#endif
