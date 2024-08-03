/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:53:03 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/08/03 18:06:19 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	check_cmdline_argument(ac, av, game);
	init_map(game, av[1]);
	init_vars(game);
	// ft_printf("%d\n", game->map.columns);
	check_map(game);
	return (0);
}
