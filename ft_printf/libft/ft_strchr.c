/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:51:58 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/06/21 12:32:22 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*(str) == (char)c)
			return ((char *)(str));
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return (NULL);
	return (NULL);
}
