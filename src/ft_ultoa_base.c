/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:09:27 by phanna            #+#    #+#             */
/*   Updated: 2019/01/08 13:27:11 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ulonglen_base(unsigned long n, int base)
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

char	*ft_ultoa_base(unsigned long long n, int base)
{
	int		len;
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_ulonglen_base(n, base);
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
