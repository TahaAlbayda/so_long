/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:53:23 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/08/03 18:04:02 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>

# define FRONT 1
# define RIGHT 2
# define LEFT 3
# define BACK 4

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

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
	void	*xmp_ptr;
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

void	ft_error(char *messeg);
void	init_map(t_game *game, char *argv);
void	check_cmdline_argument(int ac, char **av, t_game *game);
char	*ft_strappend(char **tmp_map, char *tmp_line);
void	check_map(t_game *game);
void	init_vars(t_game *game);

#endif