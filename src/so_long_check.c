#include "so_long.h"

int	wall_checker(char **map, int y, int x, int turn)
{
	int	bord;

	bord = ft_strlen(map[y]) - 1;
	while (x < bord)
	{
		if (map[y][x] != '1')
			return (0);
		x++;
	}
	turn++;
	while (map[y])
		y++;
	if (turn == 1)
		return (wall_checker(map, y - 1, 0, turn));
	x = 0;
	while (--y > 0)
	{
		if (map[y][x] != '1' || map[y][bord] != '1')
			return (0);
	}
	return (1);
}

int	is_rectangle(char *line, int cmp, int temp)
{
	temp = ft_strlen(line);
	if (!ft_strchr(line, '\n'))
		temp++;
	if (temp != cmp)
		return (free(line), 0);
	return (1);
}

int	line_counter(int fd, int temp)
{
	int		count;
	int		cmp;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	cmp = ft_strlen(line);
	if (cmp <= 1)
		return (free(line), 0);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
		if (line && !is_rectangle(line, cmp, temp))
			return (0);
	}
	if (cmp - 1 == count)
		return (0);
	return (count);
}

int	map_checker(char *name)
{
	int	fd;
	int	line_count;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	line_count = line_counter(fd, 0);
	if (line_count <= 0)
		return (0);
	close(fd);
	return (1);
}

int	name_checker(char *name)
{
	int	len;
	int	result;

	if (!name)
		return (0);
	len = ft_strlen(name);
	if (len < 4 || ft_strncmp(&name[len - 4], ".ber", 4) != 0)
		return (0);
	result = map_checker(name);
	if (result <= 0)
		return (0);
	return (1);
}
