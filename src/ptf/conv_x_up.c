/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:37:48 by phanna            #+#    #+#             */
/*   Updated: 2019/01/14 16:52:57 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_x_up(t_printf *box, t_check *flag)
{
	int		i;
	int		arg;
	char	*str;

	box->i++;
	i = -1;
	arg = va_arg(box->ap, unsigned int);
	str = ft_uitoa_base(arg, 16);
	flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->hash && arg > 0 ? fill_str(box, 'X') : 0;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	i = 0;
	while (flag->width > (int)ft_strlen(str) && !flag->minos)
	{
		flag->zero ? fill_str(box, '0') : fill_str(box, 32);
		flag->width--;
	}
	while (str[i])
		fill_str(box, str[i++]);
	while ((flag->width-- >= (int)ft_strlen(str)) && flag->minos)
		fill_str(box, 32);
	free(str);
}

void	conv_lx_up(t_printf *box, t_check *flag)
{
	int					i;
	unsigned long long	arg;
	char				*str;

	box->i++;
	i = -1;
	arg = va_arg(box->ap, unsigned long long);
	str = ft_ultoa_base(arg, 16);
	flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->hash && arg > 0 ? fill_str(box, 'X') : 0;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	i = 0;
	while (flag->width-- > (int)ft_strlen(str) && !flag->minos)
		flag->zero ? fill_str(box, '0') : fill_str(box, 32);
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
