/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarmol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:03:37 by fmarmol           #+#    #+#             */
/*   Updated: 2015/02/28 15:51:14 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

static init_colors(void)
{
	start_color();
	init_pair(1,COLOR_BLACK, COLOR_WHITE);
	init_pair(3,COLOR_BLACK, COLOR_BLUE);
	init_pair(5,COLOR_BLACK, COLOR_GREEN);
	init_pair(9,COLOR_BLACK, COLOR_RED);
	init_pair(17,COLOR_BLACK, COLOR_YELLOW);
	init_pair(33,COLOR_BLACK, COLOR_MAGENTA);
	init_pair(65,COLOR_BLACK, COLOR_CYAN);
	init_pair(125,COLOR_BLACK, COLOR_BLUE);
}

void init_ncurses(t_env * env)
{
	int y;
	int x;

	y = COLS;
	x = LINES;
	initscr();
	init_colors();
	timeout(100);
	noecho();
	nonl();
	cbreak();
	curs_set(0);
	env->win = stdscr;
	keypad(stdscr,true);
	getmaxyx(stdscr, y, x);
	env->trows=y;
	env->tcols=x;
	env->nrows=4;
	env->ncols=4;
}
