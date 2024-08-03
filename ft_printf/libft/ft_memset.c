/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:51:19 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/06/21 10:02:08 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*p;

	p = s;
	while (n--)
	{
		*(unsigned char *)s = (unsigned char)c;
		s++;
	}
	return (p);
}
