#include "so_long.h"

void	move(int x, int y, t_info *info)
{
	if (info->map[info->P_y + y][info->P_x + x] != '1')
	{
		if (info->map[info->P_y + y][info->P_x + x] == '0')
		{
			info->map[info->P_y][info->P_x] = '0';
			mlx_put_image_to_window(info->mlx, info->win, info->background, info->P_x * 64, info->P_y * 64);
			info->P_x = info->P_x + x;
			info->P_y = info->P_y + y;
			mlx_put_image_to_window(info->mlx, info->win, info->mouse, info->P_x * 64, info->P_y * 64);
			info->map[info->P_y][info->P_x] = 'P';
		}
		else if (info->map[info->P_y + y][info->P_x + x] == 'C')
		{
			info->map[info->P_y][info->P_x] = '0';
			mlx_put_image_to_window(info->mlx, info->win, info->background, info->P_x * 64, info->P_y * 64);
			info->P_x = info->P_x + x;
			info->P_y = info->P_y + y;
			info->map[info->P_y][info->P_x] = 'P';
			mlx_put_image_to_window(info->mlx, info->win, info->background, info->P_x * 64, info->P_y * 64);
			mlx_put_image_to_window(info->mlx, info->win, info->mouse, info->P_x * 64, info->P_y * 64);
			info->coins--;
		}
		else if (info->map[info->P_y + y][info->P_x + x] == 'E' && info->coins == 0)
		{
			info->map[info->P_y][info->P_x] = '0';
			mlx_put_image_to_window(info->mlx, info->win, info->background, info->P_x * 64, info->P_y * 64);
			exit(0);
			close_program(info, 0);
		}
		info->step++;
		printf("\nStep: %d", info->step);
		printf("\ninfo->coins = %d", info->coins);
	}
}

int	key_hook(int code, t_info *info)
{
	if (code == 53)
		close_program(info, 0);
	if (code == 13)
		move(0, -1, info);
	if (code == 0)
		move(-1, 0, info);
	if (code == 1)
		move(0, 1, info);
	if (code == 2)
		move(1, 0, info);
	return (0);
}