/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:56:11 by awoods            #+#    #+#             */
/*   Updated: 2021/08/08 21:56:13 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_side(t_info *info, int y)
{
	while (y < info->max_y && ft_strlen(info->map[y + 1]))
	{
		if (ft_strlen(info->map[y]) != ft_strlen(info->map[y + 1]))
			invalid_map(info);
		y++;
	}
}

void	parsing_map(t_info *info, int x, int y)
{
	if (info->max_y < 3 || info->max_x < 3 || info->character != 1 || \
	info->escape < 1 || info->coins < 1 || info->background < 1)
		invalid_map(info);
	while (x < info->max_x)
	{
		if (info->map[0][x] != '1' || info->map[info->max_y - 1][x] != '1')
			invalid_map(info);
		x++;
	}
	while (y < info->max_y)
	{
		if (info->map[y][0] != '1' || info->map[y][info->max_x - 1] != '1')
			invalid_map(info);
		y++;
	}
	check_side(info, 0);
}
