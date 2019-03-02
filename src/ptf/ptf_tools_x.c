/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_tools_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bam <bam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 17:57:52 by bam               #+#    #+#             */
/*   Updated: 2019/01/24 14:03:39 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_void_prec_x(t_printf *box, t_check *flag, const char *str, int a)
{
	if (flag->prec == 0 && flag->width == 0 && flag->ifprec != 1)
		return ;
	if (ft_strcmp(str, "debut") == 0)
	{
		while (flag->to_fill_s > 0)
		{
			fill_str(box, ' ');
			flag->to_fill_s--;
		}
		flag->hash && a > 0 ? fill_str(box, '0') : 0;
		flag->hash && a > 0 ? fill_str(box, 'x') : 0;
		while (flag->to_fill_z)
		{
			flag->space ? flag->zero-- : 0;
			fill_str(box, '0');
			flag->to_fill_z--;
		}
	}
	fill_void_prec_x2(box, flag, str);
}

void	fill_void_prec_x2(t_printf *box, t_check *flag, const char *s)
{
	if (ft_strcmp(s, "minos") == 0)
		while (flag->to_fill_z)
		{
			fill_str(box, '0');
			flag->to_fill_z--;
		}
	if (ft_strcmp(s, "end") == 0 && flag->to_fill_s > 0)
		while (flag->to_fill_s)
		{
			fill_str(box, ' ');
			flag->to_fill_s--;
		}
}

void	fill_void_prec_x_up(t_printf *box, t_check *flag, const char *s, int a)
{
	if (flag->prec == 0 && flag->width == 0 && flag->ifprec != 1)
		return ;
	if (ft_strcmp(s, "debut") == 0)
	{
		while (flag->to_fill_s > 0)
		{
			fill_str(box, ' ');
			flag->to_fill_s--;
		}
		flag->hash && a > 0 ? fill_str(box, '0') : 0;
		flag->hash && a > 0 ? fill_str(box, 'X') : 0;
		while (flag->to_fill_z)
		{
			flag->space ? flag->zero-- : 0;
			fill_str(box, '0');
			flag->to_fill_z--;
		}
	}
	fill_void_prec_x_up2(box, flag, s);
}

void	fill_void_prec_x_up2(t_printf *box, t_check *flag, const char *s)
{
	if (ft_strcmp(s, "minos") == 0)
		while (flag->to_fill_z)
		{
			fill_str(box, '0');
			flag->to_fill_z--;
		}
	if (ft_strcmp(s, "end") == 0 && flag->to_fill_s > 0)
		while (flag->to_fill_s)
		{
			fill_str(box, ' ');
			flag->to_fill_s--;
		}
}
