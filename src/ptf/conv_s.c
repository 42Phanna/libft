/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:38:44 by phanna            #+#    #+#             */
/*   Updated: 2019/01/08 11:40:02 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_100(t_printf *box, t_check *flag)
{
	box->i++;
	while (flag->width-- > 1 && !flag->minos)
		flag->zero ? fill_str(box, '0')
			: fill_str(box, 32);
	fill_str(box, '%');
	while (flag->width-- > 0 && flag->minos)
		fill_str(box, 32);
}

void	conv_c(t_printf *box, t_check *flag)
{
	char	arg;

	box->i++;
	arg = va_arg(box->ap, int);
	while (flag->width-- > 1 && !flag->minos)
		flag->zero ? fill_str(box, '0') : fill_str(box, 32);
	fill_str(box, arg);
	while ((flag->width-- > 0) && flag->minos)
		fill_str(box, 32);
}

void	conv_s(t_printf *box, t_check *flag)
{
	int		i;
	int		len;
	char	*arg;

	i = 0;
	box->i++;
	arg = va_arg(box->ap, char *);
	arg == NULL ? arg = "(null)" : 0;
	if (flag->prec < (int)ft_strlen(arg) && flag->ifprec == 1)
		len = flag->prec;
	else
		len = (int)ft_strlen(arg);
	while (flag->width-- > len && !flag->minos)
		flag->zero ? fill_str(box, '0') : fill_str(box, 32);
	if (flag->ifprec == 1)
		while (flag->prec-- > 0 && arg[i])
			fill_str(box, arg[i++]);
	else
		while (arg[i])
			fill_str(box, arg[i++]);
	while (flag->width-- >= len && flag->minos)
		fill_str(box, 32);
}
