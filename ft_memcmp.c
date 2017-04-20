/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:28:23 by phanna            #+#    #+#             */
/*   Updated: 2017/04/19 17:02:45 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (((unsigned char*)s1)[i] == ((unsigned char *)s2)[i] && i < n)
		i++;
	if (((unsigned char*)s1)[i] && ((unsigned char*)s2)[i])
		return (0);
	return(((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
