/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:52:41 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/06/21 10:13:03 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*r;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	r = (char *)malloc((len + 1) * sizeof(char));
	if (!r)
		return (0);
	while (i < len)
	{
		r[i] = *(s + start + i);
		i++;
	}
	r[i] = '\0';
	return (r);
}
