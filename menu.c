#include <game_2048.h>

extern int fd;

int menu(t_env *env)
{
	char	*choices[4] = {"4x4","5x5","3x4", "Quit"};
	ITEM	**my_items;
	MENU	*my_menu;
	int		i;
	int		ch;
	ITEM	*cur;

	i = 0;
	my_items = (ITEM **)malloc(sizeof(ITEM *) * 5);
	while (i < 4)
	{
		my_items[i] = new_item(choices[i], choices[i]);
		i++;
	}
	my_items[4] = (ITEM *)NULL;
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
	if (ft_strcmp(choices[0], (char *)item_name(cur)) == 0)
	{
		env->nrows = 4;
		env->ncols = 4;
	}
	if (ft_strcmp(choices[1], (char *)item_name(cur)) == 0)
	{
		env->nrows = 5;
		env->ncols = 5;
	}
	if (ft_strcmp(choices[2], (char *)item_name(cur)) == 0)
	{
		env->nrows = 3;
		env->ncols = 4;
	}
	if (ft_strcmp(choices[3], (char *)item_name(cur)) == 0)
		return (0);
	return (1);
}
