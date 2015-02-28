/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:03:22 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/02/28 10:24:55 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

struct		s_grill
{
	int		**grill;
	int		*free_spot;
	int		number_of_free_spot;
	int		move;
}			t_grill;

#endif
