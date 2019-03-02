/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_tools_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:13:59 by phanna            #+#    #+#             */
/*   Updated: 2019/01/24 11:36:01 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cmp_fill_o(t_check *flag, int arg)
{
	if (flag->width > flag->len && flag->zero && !flag->minos)
		flag->to_fill_z = flag->width - flag->len;
	else if (flag->width > flag->len)
	{
		flag->to_fill_s = flag->width - flag->len;
		flag->hash && arg ? flag->to_fill_s-- : 0;
		flag->hash && arg ? flag->to_fill_z++ : 0;
	}
	else if (flag->width == 0 && flag->hash && arg != 0)
		flag->to_fill_z++;
}

void	fill_void_o(t_printf *box, t_check *flag, const char *str)
{
	if (ft_strcmp(str, "debut") == 0)
	{
		while (flag->to_fill_s > 0)
		{
			fill_str(box, ' ');
			flag->to_fill_s--;
		}
		while (flag->to_fill_z > 0)
		{
			fill_str(box, '0');
			flag->to_fill_z--;
		}
	}
	if (ft_strcmp(str, "minos") == 0)
		while (flag->to_fill_z > 0)
		{
			fill_str(box, '0');
			flag->to_fill_z--;
		}
	while (flag->to_fill_s > 0 && ft_strcmp(str, "end") == 0)
	{
		fill_str(box, 32);
		flag->to_fill_s--;
	}
}

void	cmp_fill_o_prec(t_check *flag, int arg)
{
	(flag->plus && arg >= 0) ? flag->len++ : 0;
	if (flag->hash)
		flag->len--;
	if ((flag->width > flag->prec) && (flag->width > flag->len))
	{
		flag->to_fill = flag->width - flag->len;
		arg == 0 ? ++flag->to_fill : 0;
	}
	if (flag->space && flag->prec <= flag->len && arg >= 0)
		flag->to_fill = 1;
	if ((flag->width < flag->prec) && (flag->prec > flag->len))
		flag->to_fill = flag->prec - flag->len;
}
