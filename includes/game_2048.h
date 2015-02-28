/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:03:22 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 10:48:50 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

typedef struct		s_grid
{
	int				**grid;
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
}					t_env;

typedef struct		s_check_signal
{
	int				trows;
	int				tcols;

}					t_check_signal;
#endif
