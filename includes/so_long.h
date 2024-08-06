/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:53:23 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/08/06 13:56:09 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

# define FRONT 1
# define RIGHT 2
# define LEFT 3
# define BACK 4

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define IMG_WIDTH 32
# define IMG_HEIGHT 32

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_ESC  			65307

# define WALL_XPM "textures/floor.xpm"
# define FLOOR_XPM "textures/wall.xpm"
# define COINS_XPM "textures/coins.xpm"
# define PLAYER_FRONT_XPM "textures/front.xpm"
# define PLAYER_LEFT_XPM "textures/left.xpm"
# define PLAYER_RIGHT_XPM "textures/right.xpm"
# define PLAYER_BACK_XPM "textures/back.xpm"
# define OPEN_EXIT_XPM "textures/open_goal.xpm"
# define EXIT_CLOSED_XPM "textures/goal_close.xpm"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full_map;
	int			rows;
	int			columns;
	int			exit;
	int			coins;
	int			players;
	t_position	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

void	ft_error(char *messeg, t_game *game);
void	init_map(t_game *game, char *argv);
void	check_cmdline_argument(int ac, char **av, t_game *game);
char	*ft_strappend(char *tmp_map, char *tmp_line);
void	check_map(t_game *game);
void	init_vars(t_game *game);
void	ft_init_sprites(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_free_all_allocated_memory(t_game *game);
int		ft_render_map(t_game *game);
int		ft_handle_input(int keysym, t_game *game);
int		ft_close_game(t_game *game);
int		ft_victory(t_game *game);
void	ft_free_map(t_game *game);
void	ft_player_move(t_game *game, int new_y, int new_x, int player_sprite);
void	ft_valid_path(t_game *game);
void	ft_is_rectengular(t_game *game);

#endif