#include "so_long.h"

void	ft_render_sprite(t_game *game, t_image sprite, int y, int x)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
	sprite.xpm_ptr, x * sprite.x, y * sprite.y);
}

void	ft_render_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
		ft_render_sprite(game, game->player_front, y, x);
	if (game->player_sprite == LEFT)
		ft_render_sprite(game, game->player_left, y, x);
	if (game->player_sprite == RIGHT)
		ft_render_sprite(game, game->player_right, y, x);
	if (game->player_sprite == BACK)
		ft_render_sprite(game, game->player_back, y, x);
}

void	ft_identify_sprite(t_game *game, int y, int x)
{
	char	parametre;

	parametre = game->map.full_map[y][x];
	if (parametre == WALL)
		ft_render_sprite(game, game->wall, y, x);
	else
		ft_render_sprite(game, game->floor, y, x);
	if (parametre == COINS)
		ft_render_sprite(game, game->coins, y, x);
	if (parametre == MAP_EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sprite(game, game->open_exit, y, x);
		else
			ft_render_sprite(game, game->exit_closed, y, x);
	}
	if (parametre == PLAYER)
		ft_render_player(game, y, x);	
}

void	ft_print_movements(t_game *game)
{
	char	*movments;
	char	*phrase;

	movments = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movments);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	ft_printf("the nb of step : %s", movments);
	free(movments);
	free(phrase);
}

void	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}
