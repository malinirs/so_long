#include "so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_check(int	n, int	znak)
{
	char	*str;
	int		len;
	int		temp;

	temp = n;
	len = 0;
	if (temp == 0)
		len = 1;
	while (temp > 0)
	{
		temp = temp / 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + znak + 1));
	if (!str)
		return (NULL);
	str[len + znak] = '\0';
	while (len > 0)
	{
		str[len - 1 + znak] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int	n)
{
	char	*str;
	int		znak;

	if (n == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	znak = 0;
	if (n < 0)
	{
		znak = 1;
		n = -n;
	}
	str = ft_check(n, znak);
	if (!str)
		return (NULL);
	if (znak == 1)
		str[0] = '-';
	return (str);
}

void	move(int x, int y, t_info *info)
{
	char *number_of_step;
	char *number_of_step2;
	char *number_of_step3;



	if (info->map[info->P_y + y][info->P_x + x] != '1')
	{
		if (info->map[info->P_y + y][info->P_x + x] == '0')
		{
			info->map[info->P_y][info->P_x] = '0';
			mlx_put_image_to_window(info->mlx, info->win, info->backgr, info->P_x * 64, info->P_y * 64);
			info->P_x = info->P_x + x;
			info->P_y = info->P_y + y;
			mlx_put_image_to_window(info->mlx, info->win, info->mouse, info->P_x * 64, info->P_y * 64);
			info->map[info->P_y][info->P_x] = 'P';
		}
		else if (info->map[info->P_y + y][info->P_x + x] == 'C')
		{
			info->map[info->P_y][info->P_x] = '0';
			mlx_put_image_to_window(info->mlx, info->win, info->backgr, info->P_x * 64, info->P_y * 64);
			info->P_x = info->P_x + x;
			info->P_y = info->P_y + y;
			info->map[info->P_y][info->P_x] = 'P';
			mlx_put_image_to_window(info->mlx, info->win, info->backgr, info->P_x * 64, info->P_y * 64);
			mlx_put_image_to_window(info->mlx, info->win, info->mouse, info->P_x * 64, info->P_y * 64);
			info->coins--;
		}
		else if (info->map[info->P_y + y][info->P_x + x] == 'E' && info->coins == 0)
		{
			info->map[info->P_y][info->P_x] = '0';
			mlx_put_image_to_window(info->mlx, info->win, info->backgr, info->P_x * 64, info->P_y * 64);
			printf("CONGRATULATIONS! YOU WIN!\n");
			close_program(info, 0);
		}
		info->step++;
		printf("Step: %d\n", info->step);


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



		mlx_string_put(info->mlx, info->win, 20, 7, 0,
					   number_of_step2);
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