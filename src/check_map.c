/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:11:17 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/08/03 18:14:17 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full_map[i][0] != WALL)
			ft_error("invalid map error in the first wall", game);
		if (game->map.full_map[i][game->map.columns] != WALL)
			ft_error("invalid map error in the last wall", game);
		i++;
	}
}

void	ft_check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full_map[0][i] != WALL)
			ft_error("invalid map error in the first line\
		of wall", game);
		if (game->map.full_map[game->map.rows][i] != WALL)
			ft_error("invalid map error in the last line\
		of wall", game);
		i++;
	}
}

void	ft_count_map_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full_map[y][x]))
				ft_error("invalid map the map contain only CEP01", game);
			else if (game->map.full_map[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full_map[y][x] == COINS)
				game->map.coins++;
			else if (game->map.full_map[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_verify_map_parameters(t_game *game)
{
	if (game->map.coins == 0)
		ft_error("invalid map there is no coins", game);
	if (game->map.players != 1)
		ft_error("invalid map there is 0 or multiple player", game);
	if (game->map.exit != 1)
		ft_error("invalid map there is 0 or multiple exit", game);
}

void	check_map(t_game *game)
{
	check_rows(game);
	ft_check_columns(game);
	ft_count_map_parameters(game);
	ft_verify_map_parameters(game);
}
