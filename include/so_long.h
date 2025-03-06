/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:40:54 by obajja            #+#    #+#             */
/*   Updated: 2025/03/06 15:42:41 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	void		*tile;
	int			cheese_count;
	int			door_count;
	int			door_x;
	int			door_y;
	int			cheese_reach;
	int			door_reach;

}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			moves;

}				t_player;

typedef struct s_init
{
	void		*mlx;
	void		*mlx_window;
	void		*img_wall;
	void		*img_grass;
	void		*img_player_left;
	void		*img_player_right;
	void		*img_player_up;
	void		*img_player_down;
	void		*img_exit;
	void		*img_exit_open;
	void		*img_collectible;
	void		*img_trap;
	void		*img_trap_ouch;

}				t_init;

typedef struct s_env
{
	t_map		*map;
	t_player	*player;
	t_init		*init;

}				t_env;

int				name_checker(char *name);
int				map_checker(char *name);
int				line_counter(int fd, int temp);
int				map_parser(t_env **env, char *name);
int				map_sizer(char *name, int *y, int *x);
int				map_filler(char *name, char ***map, int y, int x);
int				wall_checker(char **map, int x, int y, int turn);
void			moving_player(int key, t_env *env, int y, int x);
void			img_set_character(t_env **env, int x, int y);
void			img_set_collectible(t_env **env, int x, int y);
void			img_set_exit(t_env **env, void *img);
void			flood_fill(char **map, int y, int x, t_env **env);
int				map_floodable(char **map, int lines, t_env **env);
int				close_window(void *mlx);
void			clean_image(t_env *env);
int				map_init_two(t_env **env);
void			printer_ink(char **map, t_env **env, int x, int y);
char			**map_creator(int x, int y, t_env **env);
void			right_win(t_env *env, int y, int x);
void			left_win(t_env *env, int y, int x);
void			up_win(t_env *env, int y, int x);
void			down_win(t_env *env, int y, int x);
void			img_set_exit_open(t_env **env);
int				map_init_three(t_env **env);
void			img_set_traps(t_env **env, int x, int y);
void			right_lose(t_env *env, int y, int x);
void			left_lose(t_env *env, int y, int x);
void			up_lose(t_env *env, int y, int x);
void			down_lose(t_env *env, int y, int x);

#endif
