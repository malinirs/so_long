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
	void	*background;
	void	*door;
	char	**map;

	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

/** окно */
	void	*mlx;
	void	*win; /** указатель на созданное окно */

/** координаты */
	int		max_x;
	int		max_y;
}				t_info;


#endif