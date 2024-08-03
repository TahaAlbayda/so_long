/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:50:21 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/06/21 09:56:34 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	tot;

	if (count && size && count > (2147483648 / size))
		return (NULL);
	tot = count * size;
	ptr = malloc(tot);
	if (!ptr)
		return (0);
	ft_bzero(ptr, tot);
	return (ptr);
}
