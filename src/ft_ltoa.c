/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:50:49 by phanna            #+#    #+#             */
/*   Updated: 2019/01/08 13:27:45 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlenlong(long long nb)
{
	int		len;

	len = 1;
	nb < 0 ? ++len : 0;
	nb < 0 ? nb = -nb : 0;
	while (nb > 9)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

char		*ft_ltoa(long long nb)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	if (nb < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	len = ft_numlenlong(nb);
	ret = (char *)ft_memalloc(len);
	ret[len] = '\0';
	nb < 0 ? ret[0] = '-' : 0;
	nb < 0 ? nb = -nb : 0;
	while (nb > 9)
	{
		ret[len - 1] = (nb % 10) + 48;
		nb /= 10;
		--len;
	}
	ret[len - 1] = nb + 48;
	return (ret);
}

char		*ft_lltoa(long long nb)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	if (nb < -9223372036854775807)
		return ("-9223372036854775808");
	len = ft_numlenlong(nb);
	ret = (char *)ft_memalloc(len);
	ret[len] = '\0';
	nb < 0 ? ret[0] = '-' : 0;
	nb < 0 ? nb = -nb : 0;
	while (nb > 9)
	{
		ret[len - 1] = (nb % 10) + 48;
		nb /= 10;
		--len;
	}
	ret[len - 1] = nb + 48;
	return (ret);
}
