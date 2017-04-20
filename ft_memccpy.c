/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:10:22 by phanna            #+#    #+#             */
/*   Updated: 2017/04/20 15:25:22 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!n)
		return (NULL);
	cc = (unsigned char)c;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = -1;
	while (++i < n && s[i] != cc && s[i] != '\0')
		d[i] = s[i];
	d[i] = s[i];
	if (s[i] == c)
		return (d + i + 1);
	return (NULL);
}
