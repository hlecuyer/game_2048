/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarmol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:22:39 by fmarmol           #+#    #+#             */
/*   Updated: 2015/03/01 13:43:15 by fmarmol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>
static void free_all(MENU *my_menu, ITEM **my_items)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free_item(my_items[i]);
		i++;
	}
	free_menu(my_menu);
}

static void init_items(ITEM **my_items)
{
	my_items[0] = new_item("4x4", "");
	my_items[1] = new_item("5x5", "");
	my_items[2] = new_item("3x4", "");
	my_items[3] = new_item("Quit", "");
	my_items[4] = (ITEM *)NULL;
}

int menu(t_env *env)
{
	int		ch;
	ITEM	**my_items;
	MENU	*my_menu;
	ITEM	*cur;

	my_items = (ITEM **)malloc(sizeof(ITEM *) * 5);
	init_items(my_items);
	my_menu = new_menu((ITEM **)my_items);
	post_menu(my_menu);
	while ((ch = getch()) != 13)
	{
		if (ch == KEY_DOWN)
			menu_driver(my_menu, REQ_DOWN_ITEM);
		if (ch == KEY_UP)
			menu_driver(my_menu, REQ_UP_ITEM);
		wrefresh(env->win);
	}
	cur = current_item(my_menu);
	if (ft_strcmp("4x4", (char *)item_name(cur)) == 0)
	{
		env->nrows = 4;
		env->ncols = 4;
	}
	if (ft_strcmp("5x5", (char *)item_name(cur)) == 0)
	{
		env->nrows = 5;
		env->ncols = 5;
	}
	if (ft_strcmp("3x4", (char *)item_name(cur)) == 0)
	{
		env->nrows = 3;
		env->ncols = 4;
	}
	if (ft_strcmp("Quit", (char *)item_name(cur)) == 0)
	{
		free_all(my_menu, my_items);
		return (0);
	}
	free_all(my_menu, my_items);
	return (1);
}
