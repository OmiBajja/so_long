#include "so_long.h"

char	**map_creator(int x, int y, t_env **env)
{
	int	i;

	i = -1;
	(*env)->map->map = ft_calloc(y + 1, sizeof(char *));
	if (!(*env)->map->map)
		return (0);
	while (++i < y)
	{
		(*env)->map->map[i] = ft_calloc(x + 1, sizeof(char));
		if (!(*env)->map->map[i])
			return (0);
	}
	return ((*env)->map->map);
}

void	clean_image(t_env *env)
{
	if (env->init->img_grass && env->init->img_wall)
	{
		mlx_destroy_image(env->init->mlx, env->init->img_grass);
		mlx_destroy_image(env->init->mlx, env->init->img_wall);
	}
	if (env->init->img_player && env->init->img_collectible
		&& env->init->img_exit && env->init->img_exit_open)
	{
		mlx_destroy_image(env->init->mlx, env->init->img_player);
		mlx_destroy_image(env->init->mlx, env->init->img_collectible);
		mlx_destroy_image(env->init->mlx, env->init->img_exit);
		mlx_destroy_image(env->init->mlx, env->init->img_exit_open);
	}
}

int	map_init_two(t_env	**env)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	(*env)->init->img_player = mlx_xpm_file_to_image((*env)->init->mlx,
			"small_rat.xpm", &x, &y);
	if (!(*env)->init->img_player)
		return (0);
	(*env)->init->img_collectible = mlx_xpm_file_to_image((*env)->init->mlx,
			"small_cheese.xpm", &x, &y);
	if (!(*env)->init->img_collectible)
		return (0);
	(*env)->init->img_exit = mlx_xpm_file_to_image((*env)->init->mlx,
			"door_close.xpm", &x, &y);
	if (!(*env)->init->img_exit)
		return (0);
	(*env)->init->img_exit_open = mlx_xpm_file_to_image((*env)->init->mlx,
			"door_open.xpm", &x, &y);
	if (!(*env)->init->img_exit)
		return (0);
	return (1);
}

void	printer_ink(char **map, t_env **env, int x, int y)
{
	if (map[y][x] == '0')
		mlx_put_image_to_window((*env)->init->mlx,
			(*env)->init->mlx_window, (*env)->init->img_grass,
			x * 32, y * 32);
	else if (map[y][x] == '1')
		mlx_put_image_to_window((*env)->init->mlx,
			(*env)->init->mlx_window, (*env)->init->img_wall,
			x * 32, y * 32);
	else if (map[y][x] == 'P')
		img_set_character(env, x, y);
	else if (map[y][x] == 'C')
		img_set_collectible(env, x, y);
	else if (map[y][x] == 'E')
	{
		(*env)->map->door_x = x;
		(*env)->map->door_y = y;
		img_set_exit(env);
	}
}
