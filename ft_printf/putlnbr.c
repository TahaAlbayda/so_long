/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:14:12 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/07/18 10:52:49 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

int	putlnbr(int nbr)
{
	char	*char_nbr;
	int		len;

	len = 0;
	char_nbr = ft_itoa(nbr);
	len = (int)ft_strlen(char_nbr);
	write(1, char_nbr, len);
	free (char_nbr);
	return (len);
}
