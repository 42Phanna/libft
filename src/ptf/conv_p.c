/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:21:46 by phanna            #+#    #+#             */
/*   Updated: 2019/01/08 11:39:22 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_p(t_printf *box, t_check *flag)
{
	void		*arg;
	int			i;
	char		*str;

	i = 0;
	box->i++;
	arg = va_arg(box->ap, void*);
	str = ft_ultoa_base((uintmax_t)arg, 16);
	flag->width -= 2;
	while (flag->width-- > (int)ft_strlen(str) && !flag->minos)
		flag->zero ? fill_str(box, '0')
			: fill_str(box, 32);
	fill_str(box, '0');
	fill_str(box, 'x');
	if (flag->ifprec == 1 && flag->prec > flag->width)
		while (flag->prec-- > 0)
			fill_str(box, str[i++]);
	else
		while (str[i])
			fill_str(box, str[i++]);
	while ((flag->width-- >= (int)ft_strlen(str)) && flag->minos)
		fill_str(box, 32);
	free(str);
}
