/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:53:21 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 15:58:43 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*tab;

	neg = 0;
	if (!n)
		return (ft_strdup("0"));
	if (n < 0 && (n *= -1))
		neg = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	if (!(tab = (char *)malloc(sizeof(char) * (len + neg + 1))))
		return (0);
	len += neg;
	tab[len--] = '\0';
	while (n)
	{
		tab[len--] = n % 10 + 48;
		n = n / 10;
	}
	if (neg)
		tab[0] = '-';
	return (tab);
}
