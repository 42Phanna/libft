/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur_power_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:50:37 by phanna            #+#    #+#             */
/*   Updated: 2018/03/05 14:18:55 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
