/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:56:12 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 15:50:58 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	i;

	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	i = 0;
	while (n)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

long	ft_longlen(long n)
{
	long	len;

	len = 0;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n = n / 10;
		++len;
	}
	return (len);
}