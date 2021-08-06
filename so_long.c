#include "so_long.h"

int	close_program(t_info *info, int code)
{
	int		j;

	j = 0;
	if (info->map)
	{
		while (j <= info->max_y)
		{
			free(info->map[j]);
			j++;
		}
		free(info->map);
	}
	exit(code);
}

void	init_icon(t_info *info)
{
	info->P_x = 0;
	info->P_y = 0;
	info->mouse = mlx_xpm_file_to_image(info->mlx, "./mouse.xpm", \
										 &info->P_x, &info->P_y);
	info->sushi = mlx_xpm_file_to_image(info->mlx, "./sushi.xpm", \
										&info->P_x, &info->P_y);
	info->wall = mlx_xpm_file_to_image(info->mlx, "./wall.xpm", \
									   &info->P_x, &info->P_y);
	info->backgr = mlx_xpm_file_to_image(info->mlx, "./square.xpm", \
										 &info->P_x, &info->P_y);
	info->door = mlx_xpm_file_to_image(info->mlx, "./door.xpm", \
									   &info->P_x, &info->P_y);
}

void	put_icon(t_info *info, int y, int x)
{
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == '1')
				mlx_put_image_to_window(info->mlx, info->win, info->wall, x * 64, y * 64);
			if (info->map[y][x] == '0')
			{
				mlx_put_image_to_window(info->mlx, info->win, info->backgr, x* 64, y * 64);
				info->background++;
			}
			if (info->map[y][x] == 'P')
			{
				mlx_put_image_to_window(info->mlx, info->win, info->mouse, x * 64, y * 64);
				info->character++;
				info->P_x = x;
				info->P_y = y;
			}
			if (info->map[y][x] == 'C')
			{
				mlx_put_image_to_window(info->mlx, info->win, info->sushi, x * 64, y * 64);
				info->coins++;
			}
			if (info->map[y][x] == 'E')
			{
				mlx_put_image_to_window(info->mlx, info->win, info->door, x * 64, y * 64);
				info->escape++;
			}
			x++;
		}
		y++;
	}
}

void	init_info_count(t_info *info)
{
	info->step = 0;
	info->character = 0;
	info->escape = 0;
	info->background = 0;
}

int	main(int argc, char **argv)
{
	t_info	info;

	check_argc_and_open_map(argc, argv, &info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.max_x * 64, info.max_y * 64, \
							  "So long: Mouse in the kitchen!");
	init_icon(&info);
	init_info_count(&info);
	put_icon(&info, 0, 0);
	parsing_map(&info, 0, 0);
	mlx_hook(info.win, 17, 0, close_program, &info);
	mlx_key_hook(info.win, key_hook, &info);
	mlx_loop(info.mlx);
}
