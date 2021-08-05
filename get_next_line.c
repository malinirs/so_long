#include "get_next_line.h"

static int 	check_remainder(char	*remainder)
{
	if (!remainder)
		return (0);
	if ((ft_strchr(remainder, '\n')))
		return (1);
	return (0);
}

static void	write_remainder(char **line, char **remainder)
{
	char	*pointer_n;
	char	*temp;

	if (*remainder == NULL)
	{
		*line = ft_strdup("");
		return ;
	}
	pointer_n = ft_strchr(*remainder, '\n');
	if (!pointer_n)
	{
		*line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return ;
	}
	else
	{
		temp = *remainder;
		pointer_n[0] = '\0';
		*line = ft_strdup(*remainder);
		pointer_n++;
		*remainder = ft_strdup(pointer_n);
		free(temp);
	}
}

static int	read_file(int fd, char **remainder, char **line, char *buffer)
{
	int	byte_was_read;

	byte_was_read = 1;
	while (byte_was_read && check_remainder(*remainder) == 0)
	{
		byte_was_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_was_read == -1)
		{
			*line = NULL;
			free(buffer);
			return (-1);
		}
		buffer[byte_was_read] = '\0';
		if (!(*remainder))
			*remainder = ft_strdup(buffer);
		else
			*remainder = ft_strjoin(*remainder, buffer);
	}
	write_remainder(line, remainder);
	free(buffer);
	if (byte_was_read)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	int				result;
	static char		*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	result = read_file(fd, &remainder, line, buffer);
	return (result);
}
