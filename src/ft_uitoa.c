/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:08:30 by phanna            #+#    #+#             */
/*   Updated: 2018/03/12 15:14:09 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*tab;

	if (!n)
		return (ft_strdup("0"));
	len = ft_uintlen(n);
	tab = (char *)ft_memalloc(len + 1);
	tab[len--] = '\0';
	while (n)
	{
		tab[len--] = n % 10 + 48;
		n = n / 10;
	}
	return (tab);
}
