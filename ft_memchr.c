/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:42:32 by phanna            #+#    #+#             */
/*   Updated: 2017/04/18 12:58:42 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ts;
	unsigned char	cc;
	size_t			i;

	ts = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (ts[i] != '\0' && ts[i] != cc)
		++i;
	if (ts[i] == cc)
	{
		return (ts + i);
	}
	i = 0;
	while (i < n)
		++i;
	return (ts + i);
}
