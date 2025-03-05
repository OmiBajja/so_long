#include "so_long.h"

void	clean_free(t_env *env)
{
	if (env->init)
	{
		if (env->init->mlx_window)
			mlx_destroy_window(env->init->mlx, env->init->mlx_window);
		if (env->init->img_grass && env->init->img_wall)
			clean_image(env);
		if (env->init->mlx)
		{
			mlx_destroy_display(env->init->mlx);
			free(env->init->mlx);
		}
		if (env->map->map)
		{
			ft_freestrs(env->map->map);
			free(env->map);
		}
		free(env->init);
		free(env->player);
		free(env);
	}
}

int	close_window(void *mlx)
{
	t_env	*env;

	env = (t_env *)mlx;
	if (env)
		clean_free(env);
	exit(0);
	return (1);
}

int	input_master(int key, t_env *env)
{
	if (key == 65307)
		close_window(env);
	if (key == 119 || key == 115 || key == 100 || key == 97)
		moving_player(key, env, env->map->player_y, env->map->player_x);
	(void)env;
	return (1);
}

int	init_mlx(t_env **env)
{
	*env = ft_calloc(1, sizeof(t_env));
	if (!*env)
		return (0);
	(*env)->init = ft_calloc(1, sizeof(t_init));
	if (!(*env)->init)
		return (0);
	(*env)->init->mlx = mlx_init();
	if (!(*env)->init->mlx)
		return (0);
	(*env)->map = ft_calloc(1, sizeof(t_map));
	if (!(*env)->map)
		return (0);
	(*env)->player = ft_calloc(1, sizeof(t_player));
	if (!(*env)->player)
		return (0);
	(*env)->player->moves = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2)
		return (1);
	if (!name_checker(argv[1]))
		return (1);
	if (!init_mlx(&env))
	{
		clean_free(env);
		return (1);
	}
	if (!map_parser(&env, argv[1]))
	{
		ft_putstr_fd("Error\n", 2);
		clean_free(env);
		return (1);
	}
	mlx_hook(env->init->mlx_window, 17, 0, close_window, env);
	mlx_hook(env->init->mlx_window, 2, 1L << 0, input_master, env);
	mlx_loop(env->init->mlx);
	clean_free(env);
	return (0);
}
