/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:08:30 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 14:31:14 by phanna           ###   ########.fr       */
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

int		ft_uintlen_base(unsigned int n, int base)
{
	int		i;

	i = 0;
	while (n)
	{
		n /= base;
		++i;
	}
	if (i == 0)
		return (1);
	return (i);
}

char	*ft_uitoa_base(unsigned int n, int base)
{
	int		len;
	char	*ret;

	if (base == 10)
		return (ft_uitoa(n));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_uintlen_base(n, base);
	ret = (char *)ft_memalloc(len + 1);
	ret[len] = 0;
	while (len-- > 0)
	{
		if (n % base < 10)
			ret[len] = n % base + '0';
		else
			ret[len] = n % base - 10 + 'a';
		n /= base;
	}
	return (ret);
}