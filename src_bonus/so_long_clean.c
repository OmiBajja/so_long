/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:53 by obajja            #+#    #+#             */
/*   Updated: 2025/03/06 16:18:51 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (env->init->img_grass)
		mlx_destroy_image(env->init->mlx, env->init->img_grass);
	if (env->init->img_wall)
		mlx_destroy_image(env->init->mlx, env->init->img_wall);
	if (env->init->img_collectible)
		mlx_destroy_image(env->init->mlx, env->init->img_collectible);
	if (env->init->img_exit)
		mlx_destroy_image(env->init->mlx, env->init->img_exit);
	if (env->init->img_exit_open)
		mlx_destroy_image(env->init->mlx, env->init->img_exit_open);
	if (env->init->img_trap)
		mlx_destroy_image(env->init->mlx, env->init->img_trap);
	if (env->init->img_player_left)
		mlx_destroy_image(env->init->mlx, env->init->img_player_left);
	if (env->init->img_player_right)
		mlx_destroy_image(env->init->mlx, env->init->img_player_right);
	if (env->init->img_player_down)
		mlx_destroy_image(env->init->mlx, env->init->img_player_down);
	if (env->init->img_player_up)
		mlx_destroy_image(env->init->mlx, env->init->img_player_up);
	if (env->init->img_trap_ouch)
		mlx_destroy_image(env->init->mlx, env->init->img_trap_ouch);
}

int	map_init_three(t_env **env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	(*env)->init->img_player_left = mlx_xpm_file_to_image((*env)->init->mlx,
			"assets/small_rat.xpm", &x, &y);
	if (!(*env)->init->img_player_left)
		return (0);
	(*env)->init->img_player_right = mlx_xpm_file_to_image((*env)->init->mlx,
			"assets/rat_right.xpm", &x, &y);
	if (!(*env)->init->img_player_right)
		return (0);
	(*env)->init->img_player_up = mlx_xpm_file_to_image((*env)->init->mlx,
			"assets/rat_up.xpm", &x, &y);
	if (!(*env)->init->img_player_up)
		return (0);
	(*env)->init->img_player_down = mlx_xpm_file_to_image((*env)->init->mlx,
			"assets/rat_down.xpm", &x, &y);
	if (!(*env)->init->img_player_down)
		return (0);
	return (1);
}

int	map_init_two(t_env **env)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	(*env)->init->img_collectible = mlx_xpm_file_to_image((*env)->init->mlx,
			"assets/small_cheese.xpm", &x, &y);
	if (!(*env)->init->img_collectible)
		return (0);
	(*env)->init->img_exit = mlx_xpm_file_to_image((*env)->init->mlx,
			"assets/door_close.xpm", &x, &y);
	if (!(*env)->init->img_exit)
		return (0);
	(*env)->init->img_exit_open = mlx_xpm_file_to_image((*env)->init->mlx,
			"assets/door_open.xpm", &x, &y);
	if (!(*env)->init->img_exit)
		return (0);
	return (map_init_three(env));
}

void	printer_ink(char **map, t_env **env, int x, int y)
{
	if (map[y][x] == '0')
		mlx_put_image_to_window((*env)->init->mlx, (*env)->init->mlx_window,
			(*env)->init->img_grass, x * 32, y * 32);
	else if (map[y][x] == '1')
		mlx_put_image_to_window((*env)->init->mlx, (*env)->init->mlx_window,
			(*env)->init->img_wall, x * 32, y * 32);
	else if (map[y][x] == 'P')
		img_set_character(env, x, y);
	else if (map[y][x] == 'C')
		img_set_collectible(env, x, y);
	else if (map[y][x] == 'T')
		img_set_traps(env, x, y);
	else if (map[y][x] == 'E')
	{
		(*env)->map->door_x = x;
		(*env)->map->door_y = y;
		img_set_exit(env, (*env)->init->img_exit);
	}
}
