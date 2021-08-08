/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_put_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:58:07 by awoods            #+#    #+#             */
/*   Updated: 2021/08/08 21:58:09 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_window(t_info *info)
{
	if (info->coins == 0)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->backgr, \
									info->exit_x * 64, info->exit_x * 64);
		mlx_put_image_to_window(info->mlx, info->win, info->door, \
									info->exit_x * 64, info->exit_x * 64);
	}
}

void	move_C(int x, int y, t_info *info)
{
	info->map[info->P_y][info->P_x] = '0';
	mlx_put_image_to_window(info->mlx, info->win, info->backgr, \
									info->P_x * 64, info->P_y * 64);
	info->P_x = info->P_x + x;
	info->P_y = info->P_y + y;
	info->map[info->P_y][info->P_x] = 'P';
	mlx_put_image_to_window(info->mlx, info->win, info->backgr, \
									info->P_x * 64, info->P_y * 64);
	if (info->mouse_x == 0 && info->mouse_y == -1)
		mlx_put_image_to_window(info->mlx, info->win, info->mouse_v, \
									info->P_x * 64, info->P_y * 64);
	else if (info->mouse_x == -1 && info->mouse_y == 0)
		mlx_put_image_to_window(info->mlx, info->win, info->mouse_l, \
									info->P_x * 64, info->P_y * 64);
	else if (info->mouse_x == 0 && info->mouse_y == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->mouse_n, \
									info->P_x * 64, info->P_y * 64);
	else if (info->mouse_x == 1 && info->mouse_y == 0)
		mlx_put_image_to_window(info->mlx, info->win, info->mouse_p, \
									info->P_x * 64, info->P_y * 64);
	info->coins--;
	info->step++;
	printf("Step: %d\n", info->step);
	open_window(info);
}

void	move_E(t_info *info)
{
	info->map[info->P_y][info->P_x] = '0';
	mlx_put_image_to_window(info->mlx, info->win, info->backgr, \
									info->P_x * 64, info->P_y * 64);
	printf("CONGRATULATIONS! YOU WIN!\n");
	close_program(info, 0);
}

void	output_counter(t_info *info)
{
	char	*number_of_step;
	char	*number_of_step2;
	char	*number_of_step3;

	number_of_step = ft_itoa(info->step);
	number_of_step3 = malloc((sizeof(char)) * 6);
	number_of_step3[0] = 'S';
	number_of_step3[1] = 't';
	number_of_step3[2] = 'e';
	number_of_step3[3] = 'p';
	number_of_step3[4] = ':';
	number_of_step2 = ft_strjoin(number_of_step3, number_of_step);
	mlx_put_image_to_window(info->mlx, info->win, info->wall, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win, info->wall, 64, 0);
	mlx_string_put(info->mlx, info->win, 17, 32, 999999, number_of_step2);
	free(number_of_step2);
}
