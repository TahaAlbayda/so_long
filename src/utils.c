/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:47:01 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/08/06 13:40:54 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *messeg, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	ft_printf("%s\n", messeg);
	exit(1);
}

void	check_cmdline_argument(int ac, char **av, t_game *game)
{
	if (ac != 2)
		ft_error("nbr of argument must be 2", game);
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		ft_error("Map file extention is wrong (It should be .ber)", game);
	game->map_alloc = false;
}

char	*ft_strappend(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

void	ft_free_map(t_game *game)
{
	int	line;

	line = 0;
	while (line < game->map.rows)
	{
		free(game->map.full_map[line]);
		line++;
	}
	free(game->map.full_map);
}
