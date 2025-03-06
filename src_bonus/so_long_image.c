/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:39:09 by obajja            #+#    #+#             */
/*   Updated: 2025/03/06 15:18:07 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_set_traps(t_env **env, int x, int y)
{
	mlx_put_image_to_window((*env)->init->mlx, (*env)->init->mlx_window,
		(*env)->init->img_trap, x * 32, y * 32);
}

void	img_set_character(t_env **env, int x, int y)
{
	mlx_put_image_to_window((*env)->init->mlx, (*env)->init->mlx_window,
		(*env)->init->img_player_left, x * 32, y * 32);
	(*env)->map->player_y = y;
	(*env)->map->player_x = x;
}

void	img_set_collectible(t_env **env, int x, int y)
{
	mlx_put_image_to_window((*env)->init->mlx, (*env)->init->mlx_window,
		(*env)->init->img_collectible, x * 32, y * 32);
	(*env)->map->cheese_count++;
}

void	img_set_exit(t_env **env, void *img)
{
	int	x;
	int	y;

	x = (*env)->map->door_x;
	y = (*env)->map->door_y;
	mlx_put_image_to_window((*env)->init->mlx, (*env)->init->mlx_window,
		img, x * 32, y * 32);
	(*env)->map->door_count++;
}

void	img_set_exit_open(t_env **env)
{
	int	x;
	int	y;

	x = (*env)->map->door_x;
	y = (*env)->map->door_y;
	mlx_put_image_to_window((*env)->init->mlx, (*env)->init->mlx_window,
		(*env)->init->img_exit_open, x * 32, y * 32);
	(*env)->map->door_count++;
}
