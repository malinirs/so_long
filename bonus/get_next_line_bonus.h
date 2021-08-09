#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <fcntl.h>  /** for OPEN **/
# include <unistd.h> /** for READ **/

int		get_next_line(int	fd, char	**line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strcpy(char *s1, char *s2);
#endif