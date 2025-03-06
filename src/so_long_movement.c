#include "so_long.h"

void	move_up(int key, t_env *env, int y, int x)
{
	char	**map2;

	map2 = env->map->map;
	if (key == 119 && map2[y - 1][x] == 'E' && env->map->cheese_count == 0)
		up_win(env, y, x);
	if (key == 119 && (map2[y - 1][x] == '0' || map2[y - 1][x] == 'C'))
	{
		if (map2[y - 1][x] == 'C')
			env->map->cheese_count--;
		if (env->map->cheese_count == 0)
			img_set_exit_open(&env);
		env->map->map[y - 1][x] = 'P';
		env->map->map[y][x] = '0';
		mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
			env->init->img_player, x * 32, (y - 1) * 32);
		mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
			env->init->img_grass, x * 32, y * 32);
		env->map->player_y -= 1;
		ft_printf("Moves Count: %d\r", env->player->moves++);
	}
}

void	move_down(int key, t_env *env, int y, int x)
{
	char	**map2;

	map2 = env->map->map;
	if (key == 115 && map2[y + 1][x] == 'E' && env->map->cheese_count == 0)
		down_win(env, y, x);
	if (key == 115 && (map2[y + 1][x] == '0' || map2[y + 1][x] == 'C'))
	{
		if (map2[y + 1][x] == 'C')
			env->map->cheese_count--;
		if (env->map->cheese_count == 0)
			img_set_exit_open(&env);
		env->map->map[y + 1][x] = 'P';
		env->map->map[y][x] = '0';
		mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
			env->init->img_player, x * 32, (y + 1) * 32);
		mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
			env->init->img_grass, x * 32, y * 32);
		env->map->player_y += 1;
		ft_printf("Moves Count: %d\r", env->player->moves++);
	}
}

void	move_right(int key, t_env *env, int y, int x)
{
	char	**map2;

	map2 = env->map->map;
	if (key == 100 && map2[y][x + 1] == 'E' && env->map->cheese_count == 0)
		right_win(env, y, x);
	if (key == 100 && (map2[y][x + 1] == '0' || map2[y][x + 1] == 'C'))
	{
		if (map2[y][x + 1] == 'C')
			env->map->cheese_count--;
		if (env->map->cheese_count == 0)
			img_set_exit_open(&env);
		env->map->map[y][x + 1] = 'P';
		env->map->map[y][x] = '0';
		mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
			env->init->img_player, (x + 1) * 32, y * 32);
		mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
			env->init->img_grass, x * 32, y * 32);
		env->map->player_x += 1;
		ft_printf("Moves Count: %d\r", env->player->moves++);
	}
}

void	move_left(int key, t_env *env, int y, int x)
{
	char	**map2;

	map2 = env->map->map;
	if (key == 97 && map2[y][x - 1] == 'E' && env->map->cheese_count == 0)
		left_win(env, y, x);
	if (key == 97 && (map2[y][x - 1] == '0' || map2[y][x - 1] == 'C'))
	{
		if (map2[y][x - 1] == 'C')
			env->map->cheese_count--;
		if (env->map->cheese_count == 0)
			img_set_exit_open(&env);
		env->map->map[y][x - 1] = 'P';
		env->map->map[y][x] = '0';
		mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
			env->init->img_player, (x - 1) * 32, y * 32);
		mlx_put_image_to_window(env->init->mlx, env->init->mlx_window,
			env->init->img_grass, x * 32, y * 32);
		env->map->player_x -= 1;
		ft_printf("Moves Count: %d\r", env->player->moves++);
	}
}

void	moving_player(int key, t_env *env, int y, int x)
{
	if (key == 119)
		move_up(key, env, y, x);
	else if (key == 115)
		move_down(key, env, y, x);
	else if (key == 100)
		move_right(key, env, y, x);
	else if (key == 97)
		move_left(key, env, y, x);
}
