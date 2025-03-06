/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_loser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:25:49 by obajja            #+#    #+#             */
/*   Updated: 2025/03/06 16:25:51 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_lose(t_env *env, int y, int x)
{
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_trap_ouch, (x + 1) * 32, y * 32);
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_grass, x * 32, y * 32);
	ft_printf("\nDAMN ARE YOU OK!?!?\n");
	close_window(env);
}

void	left_lose(t_env *env, int y, int x)
{
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_trap_ouch, (x - 1) * 32, y * 32);
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_grass, x * 32, y * 32);
	ft_printf("\nOUCH!!\n");
	close_window(env);
}

void	up_lose(t_env *env, int y, int x)
{
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_trap_ouch, x * 32, (y - 1) * 32);
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_grass, x * 32, y * 32);
	ft_printf("\nOUCH THAT HURTS!!\n");
	close_window(env);
}

void	down_lose(t_env *env, int y, int x)
{
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_trap_ouch, x * 32, (y + 1) * 32);
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_grass, x * 32, y * 32);
	ft_printf("\nRIP RAT!!\n");
	close_window(env);
}
