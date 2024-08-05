#include "so_long.h"

void	ft_play_move(t_game *game, int new_y, int new_x, int player_spirite);

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		ft_play_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		ft_play_move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		ft_play_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		ft_play_move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (keysym == KEY_ESC)
		ft_close_game(game);
	return (0);
}

void	ft_play_move(t_game *game, int new_y, int new_x, int player_spirite)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full_map[new_y][new_x] == MAP_EXIT && game->map.coins == 0)
		ft_victory(game);
	else if (game->map.full_map[new_y][new_x] == COINS
		|| (game->map.full_map[new_y][new_x] == FLOOR))
	{
		game->map.full_map[last_y][last_x] == FLOOR;
		if (game->map.full_map[new_y][new_x] == COINS)
			game->map.coins--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full_map[new_y][new_x] == PLAYER;
		game->movements++;
		ft_render_map(game);
	}
}