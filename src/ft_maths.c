/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:47:30 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 15:54:03 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb > 0 && nb < 13)
	{
		if (nb >= 1)
			return (nb * ft_factorial(nb - 1));
	}
	return (0);
}

int	ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_power(nb, power - 1));
}

long	ft_recur_power_long(long long nb, int pow)
{
	if (nb == 1)
		return (1);
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	if (nb == 0)
		return (0);
	return (nb * ft_recur_power_long(nb, pow - 1));
}

int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	while ((i * i) < nb)
		i++;
	if ((i * i) == nb)
		return (i);
	else
		return (0);
}