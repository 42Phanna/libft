/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:51:06 by phanna            #+#    #+#             */
/*   Updated: 2017/04/18 10:05:11 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tmpdst;
	const char	*tmpsrc;

	i = 0;
	tmpdst = (char*)dst;
	tmpsrc = (const char *)src;
	while (i < len)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	dst = (void*)tmpdst;
	return (dst);
}
