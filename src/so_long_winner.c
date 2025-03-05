#include "so_long.h"

void	right_win (t_env *env, int y, int x)
{
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_player, (x + 1) * 32, y * 32);
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_grass, x * 32, y * 32);
	ft_printf("\nYOU WON!!\n");
	close_window(env);
}

void	left_win (t_env *env, int y, int x)
{
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_player, (x - 1) * 32, y * 32);
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_grass, x * 32, y * 32);
	ft_printf("\nYOU WON!!\n");
	close_window(env);
}

void	up_win (t_env *env, int y, int x)
{
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_player, x * 32, (y - 1) * 32);
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_grass, x * 32, y * 32);
	ft_printf("YOU WON!!\n");
	close_window(env);
}

void	down_win (t_env *env, int y, int x)
{
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_player, x * 32, (y + 1) * 32);
	mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
		env->init->img_grass, x * 32, y * 32);
	ft_printf("YOU WON!!\n");
	close_window(env);
}