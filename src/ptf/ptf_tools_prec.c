/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_tools_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:28:52 by phanna            #+#    #+#             */
/*   Updated: 2019/01/24 11:46:12 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cmp_fill_prec(t_check *flag, int arg)
{
	if (flag->space && flag->width <= flag->len && arg >= 0)
		flag->to_fill = 1;
	if (flag->prec >= flag->width || arg == 0)
	{
		if (flag->width > flag->prec)
		{
			arg == 0 ? flag->len-- : 0;
			flag->to_fill = flag->width - flag->len;
		}
		else
		{
			if (arg < 0)
				flag->to_fill = flag->prec - flag->len + 1;
			else
				flag->to_fill = flag->prec - flag->len;
		}
	}
	else
	{
		flag->to_fill = flag->width - flag->len;
	}
	w_fill(flag, arg);
}

void	w_fill(t_check *flag, int arg)
{
	flag->prec == 0 ? flag->to_fill_s = flag->width - flag->len : 0;
	flag->prec > flag->len ? flag->to_fill_z = flag->prec - flag->len : 0;
	if (flag->width <= flag->prec && flag->width > flag->len
		&& flag->ifprec && flag->prec)
	{
		if (flag->width <= flag->prec)
			flag->to_fill_s = 0;
		else
			flag->to_fill_s = flag->width - flag->len;
	}
	else if (flag->width > flag->prec && flag->ifprec && flag->prec)
	{
		if (flag->prec > flag->len)
		{
			if (flag->plus || arg < 0)
				flag->to_fill_s = flag->width - flag->prec - 1;
			else
				flag->to_fill_s = flag->width - flag->prec;
		}
		else
			flag->to_fill_s = flag->width - flag->len;
	}
	arg == 0 ? flag->to_fill_z = flag->prec : 0;
	if (flag->to_fill_z > 0 && flag->hash)
		flag->to_fill_z--;
}

void	fill_void_prec(t_printf *box, t_check *flag, const char *str, int arg)
{
	if (flag->prec == 0 && flag->width == 0 && flag->ifprec != 1)
		return ;
	if (ft_strcmp(str, "debut") == 0 && flag->space == 1 && flag->to_fill
		&& arg >= 0)
	{
		fill_str(box, ' ');
		flag->to_fill_s--;
	}
	if (ft_strcmp(str, "debut") == 0)
	{
		while (flag->to_fill_s-- > 0)
			fill_str(box, ' ');
		(arg >= 0 && flag->plus) ? fill_str(box, '+') : 0;
		(arg < 0 && str[0] != '-') ? fill_str(box, '-') : 0;
		(arg < 0 && str[0] != '-') ? arg = -arg : 0;
		while (flag->to_fill_z)
		{
			flag->space ? flag->zero-- : 0;
			fill_str(box, '0');
			flag->to_fill_z--;
		}
	}
	fill_void_prec2(box, flag, str, arg);
}

void	fill_void_prec2(t_printf *box, t_check *flag, const char *str, int arg)
{
	if (ft_strcmp(str, "minos") == 0)
	{
		arg >= 0 && flag->plus ? fill_str(box, '+') : 0;
		if (arg >= 0 && flag->space)
		{
			fill_str(box, ' ');
			flag->to_fill_s--;
		}
		if (arg < 0 && str[0] != '-')
		{
			fill_str(box, '-');
			arg = -arg;
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
