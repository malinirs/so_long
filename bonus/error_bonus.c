/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:57:33 by awoods            #+#    #+#             */
/*   Updated: 2021/08/08 21:57:40 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	invalid_map(t_info *info)
{
	printf("Error: invalid map");
	close_program(info, -1);
}

void	file_read_error(t_info *info)
{
	printf("File read error!");
	info->map = NULL;
	close_program(info, -1);
}

void	memory_allocation_error(t_info *info)
{
	printf("Memory allocation error!");
	info->map = NULL;
	close_program(info, -1);
}

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
