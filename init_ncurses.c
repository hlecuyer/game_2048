/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarmol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:03:37 by fmarmol           #+#    #+#             */
/*   Updated: 2015/02/28 12:46:52 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

void init_ncurses(t_env * env)
{
	int y;
	int x;

	y = COLS;
	x = LINES;
	initscr();
	env->win = stdscr;
	noecho();
	raw();
	nonl();
	cbreak();
	keypad(stdscr,true);
	getmaxyx(stdscr, y, x);
	env->trows=y;
	env->tcols=x;
	env->nrows=4;
	env->ncols=4;
}
