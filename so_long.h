#ifndef SO_LONG_H
# define SO_LONG_H

#include "qmlx/mlx.h"
#include "get_next_line.h"
#include <stdio.h>

typedef struct	s_info
{
/** изображение */
	void	*mouse;
	void	*sushi;
	void	*wall;
	void	*backgr;
	void	*door;
	char	**map;

/** окно */
	void	*mlx;
	void	*win; /** указатель на созданное окно */

/** координаты */
	int		max_x;
	int		max_y;
	int		P_x;
	int		P_y;

/** счетчики */
	int		step;
	int		coins;
	int		character;
	int		escape;
	int		background;
}				t_info;

void	check_argc_and_open_map(int argc, char **argv, t_info *info);
void	parsing_map(t_info *info, int x, int y);
void	invalid_map(t_info *info);
int		close_program(t_info *info, int code);
int		key_hook(int code, t_info *info);

#endif