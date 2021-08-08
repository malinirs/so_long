/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:58:17 by awoods            #+#    #+#             */
/*   Updated: 2021/08/08 21:58:21 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_symbol_map(t_info *info, int x, int y)
{
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] != '1' && info->map[y][x] != '0' && \
			info->map[y][x] != 'P' && info->map[y][x] != 'C' && \
			info->map[y][x] != 'E')
				invalid_map(info);
			x++;
		}
		y++;
	}
}

static int	check_len_y(char **argv, t_info *info)
{
	int		y;
	int		fd;
	int		len;
	char	c;

	y = 0;
	len = 0;
	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
		file_read_error(info);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			y++;
		len++;
	}
	if (len < 0)
		memory_allocation_error(info);
	close(fd);
	return (y + 2);
}

static void	open_file(t_info *info, char **argv)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
	info->map = (char **)malloc(sizeof(char *) * (check_len_y(argv, info)));
	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
		file_read_error(info);
	while (get_next_line(fd, &line))
	{
		info->map[y] = line;
		if (!info->map[y])
			close_program(info, -1);
		y++;
	}
	info->map[y] = line;
	info->max_y = y;
	info->max_x = ft_strlen(info->map[0]);
	close(fd);
}

static void	check_extension_file(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i + 1] != 'b' || str[i + 2] != 'e' || str[i + 3] != 'r')
	{
		printf("Error: invalid map");
		exit(1);
	}
}

void	check_argc_and_open_map(int argc, char **argv, t_info *info)
{
	if (argc == 1)
	{
		printf("Error: file is missing\n");
		info->map = NULL;
		close_program(info, 1);
	}
	else if (argc == 2)
	{
		check_extension_file(argv[1]);
		open_file(info, argv);
		check_symbol_map(info, 0, 0);
	}
	else if (argc > 2)
	{
		printf("Error: many arguments\n");
		info->map = NULL;
		close_program(info, 1);
	}
}
