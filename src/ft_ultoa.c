/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:09:49 by phanna            #+#    #+#             */
/*   Updated: 2018/03/12 15:14:08 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ulonglonglen(unsigned long long n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

char	*ft_ultoa(unsigned long long n)
{
	int		len;
	char	*tab;

	if (!n)
		return (ft_strdup("0"));
	len = ft_ulonglonglen(n);
	tab = (char *)ft_memalloc(len + 1);
	tab[len--] = '\0';
	while (n)
	{
		tab[len--] = n % 10 + 48;
		n = n / 10;
	}
	return (tab);
}
