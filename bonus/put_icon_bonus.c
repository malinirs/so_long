/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_icon_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:55:57 by awoods            #+#    #+#             */
/*   Updated: 2021/08/08 21:56:00 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_icon_0(t_info *info, int y, int x)
{
	mlx_put_image_to_window(info->mlx, info->win, info->backgr, \
										x * 64, y * 64);
	info->background++;
}

void	put_icon_P(t_info *info, int y, int x)
{
	mlx_put_image_to_window(info->mlx, info->win, info->mouse_v, \
										x * 64, y * 64);
	info->character++;
	info->P_x = x;
	info->P_y = y;
}

void	put_icon_C(t_info *info, int y, int x)
{
	mlx_put_image_to_window(info->mlx, info->win, info->sushi, \
										x * 64, y * 64);
	info->coins++;
}

void	put_icon_E(t_info *info, int y, int x)
{
	mlx_put_image_to_window(info->mlx, info->win, info->close, \
										x * 64, y * 64);
	info->escape++;
	info->exit_x = x;
	info->exit_y = y;
}
