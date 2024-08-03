/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:46:29 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/07/06 14:19:31 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
char	*ft_itoa(int n);
int		putlnbr(int nbr);
int		putlchr(char c);
int		putlhex(char c, unsigned int nbr);
int		putlunbr(unsigned int nbr);
int		putlstr(char *str);
int		putlptr(void *nbr);

#endif