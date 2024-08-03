/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:11:49 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/06/25 14:16:16 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ptr_print(char *base, unsigned long long nbr, int *len)
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
		ptr_print(base, nbr / 16, len);
		ptr_print(base, nbr % 16, len);
	}
}

int	putlptr(void *nbr)
{
	char	*base;
	int		len;

	if (!nbr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 0;
	base = "0123456789abcdef";
	write(1, "0x", 2);
	ptr_print(base, (unsigned long long)nbr, &len);
	len += 2;
	return (len);
}
