#include <game_2048.h>

void left_fusion(t_env *env, t_grid *grid)
{
	int x;
	int y;
	
	x = 0;
	while (x < env->nrows)
	{
		y = 0;
		while (y < env->ncols - 1)
		{
			if (grid->grid[x][y].value == grid->grid[x][y + 1].value)
			{
				grid->grid[x][y].value *= 2;
				grid->grid[x][y + 1].value = 0;
			}
			y++;
		}
		x++;
	}
	left_shift(env,grid);
}
