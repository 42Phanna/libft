/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_fill_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:59:09 by phanna            #+#    #+#             */
/*   Updated: 2019/01/24 14:05:23 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cmp_fill_x(t_check *flag)
{
	if (flag->width > flag->len && flag->zero && !flag->minos)
		flag->to_fill_z = flag->width - flag->len;
	else if (flag->width > flag->len)
		flag->to_fill_s = flag->width - flag->len;
}

void	cmp_fill_prec_x(t_check *flag, int arg)
{
	if (flag->prec >= flag->width && flag->prec > flag->len)
	{
		flag->to_fill_z = flag->prec - flag->len;
		flag->hash ? flag->to_fill_z += 2 : 0;
	}
	else if (flag->prec >= flag->len - 2 && flag->hash && flag->prec != 0)
	{
		flag->hash ? flag->len -= 2 : 0;
		flag->len < 0 ? flag->len = 0 : 0;
		flag->to_fill_z = flag->prec - flag->len;
		flag->to_fill_z < 0 ? flag->to_fill_z = 0 : 0;
		arg == 0 && flag->prec == 1 ? flag->to_fill_z-- : 0;
	}
	else if (flag->width > flag->prec && flag->width > flag->len
		&& flag->prec > flag->len)
		cmp_fill_prec_x2(flag);
	else if (flag->width > flag->prec && flag->width > flag->len)
	{
		flag->to_fill_s = flag->width - flag->len;
		arg == 0 ? flag->to_fill_s++ : 0;
	}
}

void	cmp_fill_prec_x2(t_check *flag)
{
	if (!flag->hash)
	{
		flag->to_fill_z = flag->prec - flag->len;
		flag->to_fill_s = flag->width - (flag->to_fill_z + flag->len);
	}
	else
	{
		flag->len -= 2;
		flag->to_fill_z = flag->prec - flag->len;
		flag->to_fill_s = flag->width - (flag->to_fill_z + flag->len + 2);
	}
}
