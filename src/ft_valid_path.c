/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:03:33 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/08/06 13:46:30 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	isvalid(int x, int y, t_game *game, t_bool **visited);
t_bool	dfs(int x, int y, t_game *game, t_bool **visited);
void	freevisited(t_bool **visited, int rows);

void	ft_valid_path(t_game *game)
{
	int		i;
	t_bool	**visited;

	i = 0;
	visited = malloc(game->map.rows * sizeof(t_bool *));
	while (i < game->map.rows)
	{
		visited[i] = ft_calloc(game->map.columns, sizeof(t_bool));
		i++;
	}
	if (!dfs(game->map.player.x, game->map.player.y, game, visited))
	{
		freevisited(visited, game->map.rows);
		ft_error("invalid map path not valid", game);
	}
	freevisited(visited, game->map.rows);
}

t_bool	isvalid(int x, int y, t_game *game, t_bool **visited)
{
	return (x >= 0 && x < game->map.rows && y >= 0 && y < game->map.columns
		&& game->map.full_map[y][x] != '1' && !visited[y][x]);
}

t_bool	dfs(int x, int y, t_game *game, t_bool **visited)
{
	static int	count;
	static t_bool	exit;

	count = 0;
	exit = false;
	if (!isvalid(x, y, game, visited))
		return (false);
	if (game->map.full_map[y][x] == 'E')
		exit = true;
	if (game->map.full_map[y][x] == 'c')
		count++;
	visited[y][x] = true;
	dfs(x - 1, y, game, visited);
	dfs(x + 1, y, game, visited);
	dfs(x, y - 1, game, visited);
	dfs(x, y + 1, game, visited);
	return (count == game->map.coins && exit);
}

void	freevisited(t_bool **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	ft_is_rectengular(t_game *game)
{
	int		rows;
	int		i;
	size_t	cols;

	i = 1;
	rows = game->map.rows;
	cols = game->map.columns;
	while (i < rows)
	{
		if (ft_strlen(game->map.full_map[i]) != cols)
			ft_error("invalid map is not rectangular", game);
		i++;
	}	
}
