/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:47:01 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/08/03 17:27:58 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *messeg)
{
	ft_printf("%s\n", messeg);
	exit(1);
}

void	check_cmdline_argument(int ac, char **av, t_game *game)
{
	if (ac != 2)
		ft_error("nbr of argument must be 2");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		ft_error("Map file extention is wrong (It should be .ber)");
	game->map_alloc = false;
}

char	*ft_strappend(char **s1, char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)calloc((ft_strlen(*s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}
