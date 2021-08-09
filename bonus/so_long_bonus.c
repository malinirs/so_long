/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:55:40 by awoods            #+#    #+#             */
/*   Updated: 2021/08/08 21:55:42 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_icon(t_info *info)
{
	info->P_x = 0;
	info->P_y = 0;
	info->mouse_n = mlx_xpm_file_to_image(info->mlx, "./icon/mouse_n.xpm", \
										 &info->P_x, &info->P_y);
	info->mouse_p = mlx_xpm_file_to_image(info->mlx, "./icon/mouse_p.xpm", \
										 &info->P_x, &info->P_y);
	info->mouse_v = mlx_xpm_file_to_image(info->mlx, "./icon/mouse_v.xpm", \
										 &info->P_x, &info->P_y);
	info->mouse_l = mlx_xpm_file_to_image(info->mlx, "./icon/mouse_l.xpm", \
										 &info->P_x, &info->P_y);
	info->sushi = mlx_xpm_file_to_image(info->mlx, "./icon/sushi.xpm", \
										&info->P_x, &info->P_y);
	info->wall = mlx_xpm_file_to_image(info->mlx, "./icon/wall.xpm", \
									   &info->P_x, &info->P_y);
	info->backgr = mlx_xpm_file_to_image(info->mlx, "./icon/square.xpm", \
										 &info->P_x, &info->P_y);
	info->door = mlx_xpm_file_to_image(info->mlx, "./icon/door.xpm", \
									   &info->P_x, &info->P_y);
	info->close = mlx_xpm_file_to_image(info->mlx, "./icon/close.xpm", \
									   &info->P_x, &info->P_y);
}

static void	put_icon(t_info *info, int y, int x)
{
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == '1')
				mlx_put_image_to_window(info->mlx, info->win, info->wall, \
										x * 64, y * 64);
			if (info->map[y][x] == '0')
				put_icon_0(info, y, x);
			if (info->map[y][x] == 'P')
				put_icon_P(info, y, x);
			if (info->map[y][x] == 'C')
				put_icon_C(info, y, x);
			if (info->map[y][x] == 'E')
				put_icon_E(info, y, x);
			x++;
		}
		y++;
	}
}

static void	init_info_count(t_info *info)
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
							  "So long bonus: bat on the hunt!");
	init_icon(&info);
	init_info_count(&info);
	put_icon(&info, 0, 0);
	parsing_map(&info, 0, 0);
	mlx_hook(info.win, 17, 0, close_program, &info);
	mlx_key_hook(info.win, key_hook, &info);
	mlx_loop(info.mlx);
}
