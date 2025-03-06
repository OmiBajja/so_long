#include "so_long.h"

void	flood_fill(char **map, int y, int x,
	t_env **env)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		(*env)->map->cheese_reach--;
	if (map[y][x] == 'E')
		(*env)->map->door_reach = 1;
	map[y][x] = 'X';
	flood_fill(map, y - 1, x, env);
	flood_fill(map, y + 1, x, env);
	flood_fill(map, y, x + 1, env);
	flood_fill(map, y, x - 1, env);
}

int	map_floodable(char **map, int lines, t_env **env)
{
	char	**map2;
	(*env)->map->cheese_reach = (*env)->map->cheese_count;
	(*env)->map->door_reach = 0;
	map2 = ft_strsdup(map, lines);
	flood_fill(map2, (*env)->map->player_y, (*env)->map->player_x, env);
	ft_freestrs(map2);
	if ((*env)->map->cheese_reach == 0 && (*env)->map->door_reach == 1)
		return (1);
	else
		return (0);
}
