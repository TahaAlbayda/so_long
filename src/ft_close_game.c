#include "so_long.h"

void	ft_close_game(t_game *game)
{
	ft_printf("Movments : ", game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf("CLOSED\n");
	exit (1);
}

void	ft_victory(t_game *game)
{
	ft_printf("Movments : ", game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf("\nYOU WIN\n");
	exit (0);
}
