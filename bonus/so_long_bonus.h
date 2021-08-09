#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "qmlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>  /** for OPEN **/
# include <unistd.h> /** for READ **/
# include <stdlib.h>

typedef struct s_info
{
	void	*mouse_n;
	void	*mouse_p;
	void	*mouse_v;
	void	*mouse_l;
	void	*sushi;
	void	*wall;
	void	*backgr;
	void	*door;
	void	*close;
	char	**map;

	void	*mlx;
	void	*win;

	int		max_x;
	int		max_y;
	int		P_x;
	int		P_y;
	int		mouse_x;
	int		mouse_y;
	int		exit_x;
	int		exit_y;

	int		step;
	int		coins;
	int		character;
	int		escape;
	int		background;
}					t_info;

void	check_argc_and_open_map(int argc, char **argv, t_info *info);
void	parsing_map(t_info *info, int x, int y);
void	invalid_map(t_info *info);
int		close_program(t_info *info, int code);
int		key_hook(int code, t_info *info);
char	**ft_split_mod(char *s, char c, t_info *info);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		get_next_line(int fd, char **line);
void	file_read_error(t_info *info);
void	memory_allocation_error(t_info *info);
void	put_icon_0(t_info *info, int y, int x);
void	put_icon_P(t_info *info, int y, int x);
void	put_icon_C(t_info *info, int y, int x);
void	put_icon_E(t_info *info, int y, int x);
char	*ft_itoa(int n);
void	output_counter(t_info *info);
void	move_E(t_info *info);
void	move_C(int x, int y, t_info *info);

#endif