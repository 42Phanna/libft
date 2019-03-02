/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_conv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:03:42 by phanna            #+#    #+#             */
/*   Updated: 2019/01/14 17:01:47 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	choose_conv_ld(t_printf *box, t_check *flag)
{
	if (flag->ifprec == 1)
		return (conv_ld_prec(box, flag));
	return (conv_ld(box, flag));
}

void	choose_conv_x_up(t_printf *box, t_check *flag)
{
	if ((flag->modif == 'L' || flag->modif == 'j' || flag->modif == 'l'
		|| flag->modif == 'z') && flag->ifprec == 1)
		return (conv_lx_up_prec(box, flag));
	if (flag->modif == 'L' || flag->modif == 'j' || flag->modif == 'l'
		|| flag->modif == 'z')
		return (conv_lx_up(box, flag));
	if (flag->ifprec == 1)
		return (conv_x_up_prec(box, flag));
	return (conv_x_up(box, flag));
}
