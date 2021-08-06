#include "so_long.h"

void	open_file(t_info *info, char **argv)
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
}

void	check_extension_file(char *str)
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
	}
	else if (argc > 2)
	{
		printf("Error: many arguments\n");
		info->map = NULL;
		close_program(info, 1);
	}
}