/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:51:34 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/08/03 18:11:52 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_for_empty_line(char *map, t_game *game);

void	init_map(t_game *game, char *argv)
{
	int		map_fd;
	char	*tmp_map;
	char	*tmp_line;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error("The Map couldn't be opened. Does the Map exist?");
	tmp_map = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		tmp_line = get_next_line(map_fd);
		if (tmp_line == NULL)
			break ;
		tmp_map = ft_strappend(&tmp_map, tmp_line);
		free(tmp_line);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(tmp_map, game);
	game->map.full_map = ft_split(tmp_map, '\n');
	game->map_alloc = true;
	free(tmp_line);
}

void	ft_check_for_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error("invalid map the map have an empty line at the beginning");
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_error("invalid map the map have a empty line at the end");
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error("invalid map the map have a empty\
						line at the middle of line");
		}
		i++;
	}
}
