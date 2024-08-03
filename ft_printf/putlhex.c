/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:18:23 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/06/25 13:19:25 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_print(char *base, unsigned int nbr, int *len)
{
	char	c;
	int		n;

	if (nbr < 16)
	{
		n = nbr % 16;
		c = *(base + n);
		write (1, &c, 1);
		*(len) += 1;
	}
	else
	{
		hex_print(base, nbr / 16, len);
		n = nbr % 16;
		c = *(base + n);
		write (1, &c, 1);
		*(len) += 1;
	}
}

int	putlhex(char c, unsigned int nbr)
{
	char	*base;
	int		len;

	len = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	hex_print(base, nbr, &len);
	return (len);
}
