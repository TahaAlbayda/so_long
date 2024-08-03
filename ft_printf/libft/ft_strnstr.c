/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:52:30 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/06/21 12:06:16 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if (!big && !n)
		return (NULL);
	if (!*little)
		return ((char *)big);
	if (little[0] == '\0' && big[0] == '\0' && n == 0)
		return ((char *)little);
	if (n == 0)
		return (NULL);
	i = 0;
	while (big[i] && i < n)
	{
		j = 0;
		while (little[j] && (i + j) < n && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
