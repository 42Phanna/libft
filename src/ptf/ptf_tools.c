/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:59:18 by phanna            #+#    #+#             */
/*   Updated: 2019/01/08 16:51:40 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cmp_fill(t_check *flag, int arg)
{
	(flag->plus && arg >= 0) ? flag->len++ : 0;
	if (flag->space && flag->width <= flag->len && arg >= 0 && !flag->plus)
		flag->to_fill = 1;
	if (flag->width > flag->len)
		flag->to_fill = flag->width - flag->len;
}

void	fill_void(t_printf *box, t_check *flag, const char *str)
{
	if (ft_strcmp(str, "debut") == 0 && flag->space == 1 && flag->to_fill)
	{
		fill_str(box, 32);
		flag->to_fill--;
	}
	while (flag->to_fill > 0 && ft_strcmp(str, "debut") == 0)
	{
		flag->zero || flag->zero == 1 ? fill_str(box, '0')
			: fill_str(box, 32);
		flag->to_fill--;
	}
	while (flag->to_fill > 0 && ft_strcmp(str, "end") == 0)
	{
		fill_str(box, 32);
		flag->to_fill--;
	}
}
