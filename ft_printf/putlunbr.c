/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlunbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:24:00 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/06/25 13:45:01 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	ft_putnbr(unsigned int n, int fd)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write (fd, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10, fd);
		c = (n % 10) + '0';
		write (fd, &c, 1);
	}
}

int	putlunbr(unsigned int nbr)
{
	int		len;

	len = 0;
	ft_putnbr(nbr, 1);
	len = count_nbr(nbr);
	return (len);
}
