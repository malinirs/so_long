#include "so_long.h"

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->addr + (y * info->line_length + x * (info->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(void)
{
	printf("Hello from key_hook!\n");
	return (0);
}

void	init_icon(t_info *info)
{
	int		img_width;
	int		img_height;

	img_height = 0;
	img_width = 0;

	info->mouse = mlx_xpm_file_to_image(info->mlx, "./icon/mouse.xpm", &img_width, &img_height);
	info->sushi = mlx_xpm_file_to_image(info->mlx, "./icon/sushi.xpm", &img_width, &img_height);
	info->wall = mlx_xpm_file_to_image(info->mlx, "./icon/wall.xpm", &img_width, &img_height);
	info->background = mlx_xpm_file_to_image(info->mlx, "./icon/square.xpm", &img_width, &img_height);
	info->door = mlx_xpm_file_to_image(info->mlx, "./icon/door.xpm", &img_width, &img_height);
}

void	put_icon(t_info *info)
{
	int		x;
	int		y;

//	exit(1);
	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x] != '\n')
		{
			if (info->map[y][x] == '1')
				mlx_put_image_to_window(info->mlx, info->win, info->wall, x * 64, y * 64);
			else if (info->map[y][x] == '0')
				mlx_put_image_to_window(info->mlx, info->win, info->background, x * 64, y * 64);
			else if (info->map[y][x] == 'C')
				mlx_put_image_to_window(info->mlx, info->win, info->sushi, x * 64, y * 64);
			else if (info->map[y][x] == 'P')
				mlx_put_image_to_window(info->mlx, info->win, info->mouse, x * 64, y * 64);
			else if (info->map[y][x] == 'E')
				mlx_put_image_to_window(info->mlx, info->win, info->door, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	draw_icon(t_info *info, char **argv)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
	info->map = (char **)malloc(sizeof(char *) * 100);
	fd = open (argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		info->map[y] = line;
		printf("%s\n", info->map[y]);
		y++;
	}
	info->map[y] = line;
	printf("%s\n", info->map[y]);
	info->max_y = y;
	info->max_x = ft_strlen(info->map[0]);

//	printf("%d\n", info->max_y);
//	printf("%d\n", info->max_x);


}

int	main(int argc, char **argv)
{
	t_info	info;

	info.mlx = mlx_init();
	init_icon(&info);
	if (argc > 1)
		draw_icon(&info, argv);
	info.win = mlx_new_window(info.mlx, info.max_x * 64, info.max_y * 64, "So "
																		 "long!");
													/** возвращает указатель на только что созданное окно */
	put_icon(&info);

//	info.img = mlx_new_image(info.mlx, 640, 480);
//	info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel, &info.line_length, &info.endian);
//	my_mlx_pixel_put(&info, 5, 5, 0x00FF0000);
//	mlx_put_image_to_window(info.mlx, info.win, info.img, 0, 0);


	mlx_key_hook(info.win, key_hook, &info);  /** печатает сообщение при нажатии клавиши */
	mlx_loop(info.mlx); /** начинает рендеринг (получение изображения) окна*/
}