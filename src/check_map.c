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
			ft_error("invalid map error in the first wall");
		if (game->map.full_map[i][game->map.columns] != WALL)
			ft_error("invalid map error in the last wall");
		i++;
	}
}

void	check_map(t_game *game)
{
	check_rows(game);
}
