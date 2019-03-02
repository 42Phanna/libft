/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_void_prec_o.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:31:41 by phanna            #+#    #+#             */
/*   Updated: 2019/01/24 11:37:20 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_void_prec_o(t_printf *box, t_check *flag, const char *str, int arg)
{
	if (flag->prec == 0 && flag->width == 0 && flag->ifprec != 1)
		return ;
	if (ft_strcmp(str, "debut") == 0)
	{
		if (flag->hash && flag->zero)
		{
			flag->to_fill_s--;
			flag->to_fill_z++;
		}
		flag->hash && !flag->zero ? fill_str(box, '0') : 0;
		while (flag->to_fill_s > 0)
		{
			fill_str(box, ' ');
			flag->to_fill_s--;
		}
		if (arg >= 0 && flag->plus)
			fill_str(box, '+');
		while (flag->to_fill_z)
		{
			fill_str(box, '0');
			flag->to_fill_z--;
		}
	}
	fill_void_prec_o2(box, flag, str, arg);
}

void	fill_void_prec_o2(t_printf *box, t_check *flag, const char *str
	, int arg)
{
	if (ft_strcmp(str, "minos") == 0)
	{
		flag->hash && flag->zero ? flag->to_fill_s-- : 0;
		flag->hash && flag->zero ? flag->to_fill_z++ : 0;
		flag->hash ? fill_str(box, '0') : 0;
		if (arg >= 0 && flag->plus)
			fill_str(box, '+');
		if (arg >= 0 && flag->space && flag->space)
		{
			fill_str(box, ' ');
			flag->to_fill_s--;
		}
		while (flag->to_fill_z)
		{
			fill_str(box, '0');
			flag->to_fill_z--;
		}
	}
	if (ft_strcmp(str, "end") == 0 && flag->to_fill_s > 0)
		while (flag->to_fill_s)
		{
			fill_str(box, ' ');
			flag->to_fill_s--;
		}
}
