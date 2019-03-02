/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:10:59 by phanna            #+#    #+#             */
/*   Updated: 2019/01/24 11:53:57 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_x(t_printf *box, t_check *flag)
{
	int		i;
	int		arg;
	char	*str;

	box->i++;
	i = 0;
	arg = va_arg(box->ap, unsigned int);
	str = ft_uitoa_base(arg, 16);
	flag->len = ft_strlen(str);
	flag->hash ? flag->len += 2 : 0;
	cmp_fill_x(flag);
	if (flag->zero == 1)
		flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	if (flag->zero == 1)
		flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	!flag->minos ? fill_void_o(box, flag, "debut") : 0;
	flag->plus && str[i] != '+' && arg >= 0 ? fill_str(box, '+') : 0;
	if (flag->zero == 0)
		flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	if (flag->zero == 0)
		flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void_o(box, flag, "end") : 0;
	free(str);
}

void	conv_hx(t_printf *box, t_check *flag)
{
	int				i;
	unsigned char	arg;
	char			*str;

	box->i++;
	i = 0;
	arg = va_arg(box->ap, int);
	str = ft_uitoa_base(arg, 16);
	flag->len = ft_strlen(str);
	flag->hash ? flag->len += 2 : 0;
	cmp_fill_x(flag);
	flag->zero == 1 && flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->zero == 1 && flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	!flag->minos ? fill_void_o(box, flag, "debut") : 0;
	flag->plus && str[i] != '+' && arg >= 0 ? fill_str(box, '+') : 0;
	if (flag->zero == 0)
		flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	if (flag->zero == 0)
		flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void_o(box, flag, "end") : 0;
	free(str);
}

void	conv_lx(t_printf *box, t_check *flag)
{
	int					i;
	unsigned long long	arg;
	char				*str;

	if (flag->prec)
		return (conv_lx_prec(box, flag));
	box->i++;
	i = 0;
	arg = va_arg(box->ap, unsigned long long);
	str = ft_ultoa_base(arg, 16);
	flag->len = ft_strlen(str);
	flag->hash ? flag->len += 2 : 0;
	cmp_fill_x(flag);
	flag->zero == 1 && flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->zero == 1 && flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	!flag->minos ? fill_void(box, flag, "debut") : 0;
	flag->plus && str[i] != '+' ? fill_str(box, '+') : 0;
	if (flag->zero == 0)
		flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	if (flag->zero == 0)
		flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void(box, flag, "end") : 0;
	free(str);
}

void	conv_jx(t_printf *box, t_check *flag)
{
	int			i;
	uintmax_t	arg;
	char		*str;

	if (flag->prec)
		return (conv_jx_prec(box, flag));
	box->i++;
	i = 0;
	arg = va_arg(box->ap, uintmax_t);
	str = ft_ultoa_base(arg, 16);
	flag->len = ft_strlen(str);
	flag->hash ? flag->len += 2 : 0;
	cmp_fill_x(flag);
	flag->zero == 1 && flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->zero == 1 && flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	!flag->minos ? fill_void(box, flag, "debut") : 0;
	flag->plus && str[i] != '+' ? fill_str(box, '+') : 0;
	if (flag->zero == 0)
		flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	if (flag->zero == 0)
		flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void(box, flag, "end") : 0;
	free(str);
}
