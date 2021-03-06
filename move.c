/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 12:09:01 by awoods            #+#    #+#             */
/*   Updated: 2021/08/08 12:09:06 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_0(int x, int y, t_info *info)
{
	info->map[info->P_y][info->P_x] = '0';
	mlx_put_image_to_window(info->mlx, info->win, info->backgr, \
									info->P_x * 64, info->P_y * 64);
	info->P_x = info->P_x + x;
	info->P_y = info->P_y + y;
	mlx_put_image_to_window(info->mlx, info->win, info->mouse_v, \
									info->P_x * 64, info->P_y * 64);
	info->map[info->P_y][info->P_x] = 'P';
	info->step++;
	printf("Step: %d\n", info->step);
}

static void	move_C(int x, int y, t_info *info)
{
	info->map[info->P_y][info->P_x] = '0';
	mlx_put_image_to_window(info->mlx, info->win, info->backgr, \
									info->P_x * 64, info->P_y * 64);
	info->P_x = info->P_x + x;
	info->P_y = info->P_y + y;
	info->map[info->P_y][info->P_x] = 'P';
	mlx_put_image_to_window(info->mlx, info->win, info->backgr, \
									info->P_x * 64, info->P_y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->mouse_v, \
									info->P_x * 64, info->P_y * 64);
	info->coins--;
	info->step++;
	printf("Step: %d\n", info->step);
}

static void	move_E(t_info *info)
{
	info->map[info->P_y][info->P_x] = '0';
	mlx_put_image_to_window(info->mlx, info->win, info->backgr, \
									info->P_x * 64, info->P_y * 64);
	printf("CONGRATULATIONS! YOU WIN!\n");
	close_program(info, 0);
}

static void	move(int x, int y, t_info *info)
{
	if (info->map[info->P_y + y][info->P_x + x] != '1')
	{
		if (info->map[info->P_y + y][info->P_x + x] == '0')
			move_0(x, y, info);
		else if (info->map[info->P_y + y][info->P_x + x] == 'C')
			move_C(x, y, info);
		else if (info->map[info->P_y + y][info->P_x + x] == 'E' &&
				 info->coins == 0)
			move_E(info);
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
