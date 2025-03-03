#include "so_long.h"

int	map_init(t_env **env)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!env || !*env)
		return (0);
	(*env)->init->img_wall = mlx_xpm_file_to_image((*env)->init->mlx,
			"small.xpm", &x, &y);
	if (!(*env)->init->img_wall)
		return (0);
	(*env)->init->img_grass = mlx_xpm_file_to_image((*env)->init->mlx,
			"small_wall.xpm", &x, &y);
	if (!(*env)->init->img_grass)
		return (0);
	return (map_init_two(env));
}

int	map_print(char **map, t_env **env, int x, int y)
{
	if (!map_init(env) || !map[y + 1])
		return (0);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			printer_ink(map, env, x, y);
		}
	}
	if ((*env)->map->door_count != 1 || (*env)->map->cheese_count < 1)
		return (0);
	return (1);
}

int	map_filler(char *name, char ***map, int y, int x)
{
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		x = 0;
		while (line[x] && x < ft_strlen(line))
		{
			(*map)[y][x] = line[x];
			x++;
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (1);
}

int	map_sizer(char *name, int *y, int *x)
{
	int		fd;
	char	*line;

	*y = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	*x = ft_strlen(line);
	if (*x <= 1)
		return (free(line), 0);
	while (line)
	{
		(*y)++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	map_parser(t_env **env, char *name)
{
	int	i;
	int	y;
	int	x;

	i = -1;
	if (!map_sizer(name, &y, &x))
		return (0);
	(*env)->map->map = ft_calloc(y + 1, sizeof(char *));
	if (!(*env)->map->map)
		return (0);
	while (++i < y)
	{
		(*env)->map->map[i] = ft_calloc(x + 1, sizeof(char));
		if (!(*env)->map->map[i])
			return (0);
	}
	map_filler(name, &(*env)->map->map, 0, 0);
	if (!wall_checker((*env)->map->map, 0, 0, 0))
		return (0);
	(*env)->map->cheese_count = 0;
	if (!map_print((*env)->map->map, env, -1, -1)
		|| !map_floodable((*env)->map->map, y, env))
		return (0);
	return (1);
}
