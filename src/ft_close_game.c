/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:53:14 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/08/06 13:49:50 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game(t_game *game)
{
	ft_printf("Movments : %d\n", game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf("CLOSED\n");
	exit (1);
}

int	ft_victory(t_game *game)
{
	ft_printf("Movments : %d\n", game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf("YOU WIN\n");
	exit (0);
}
