/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:45:12 by phanna            #+#    #+#             */
/*   Updated: 2017/09/25 09:44:22 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
