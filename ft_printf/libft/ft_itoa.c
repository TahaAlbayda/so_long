/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:50:56 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/06/21 10:01:30 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*fill(char *r, int n, int count)
{
	int		sign;

	sign = 0;
	if (n < 0)
	{
		sign++;
		n *= -1;
	}
	r[count] = '\0';
	while (--count)
	{
		r[count] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		r[0] = '-';
	else
		r[0] = (n % 10) + '0';
	return (r);
}

char	*ft_itoa(int n)
{
	int		n_count;
	char	*r;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_count = count_n(n);
	r = (char *)malloc((n_count + 1) * sizeof(char));
	if (!r)
		return (0);
	r = fill(r, n, n_count);
	if (!r)
		return (0);
	return (r);
}
