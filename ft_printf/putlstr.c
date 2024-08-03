/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:19:58 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/07/18 10:54:24 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	len(char *s)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		i++;
		j++;
	}	
	return (i);
}

int	putlstr(char *str)
{
	int	i;

	if (!str)
	{
		i = write(1, "(null)", 6);
	}
	if (str)
	{
		i = write(1, str, len(str));
	}
	return (i);
}
