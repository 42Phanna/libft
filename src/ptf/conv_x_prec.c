/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:45:46 by phanna            #+#    #+#             */
/*   Updated: 2019/01/24 12:08:56 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_x_prec(t_printf *box, t_check *flag)
{
	int		i;
	int		s;
	int		arg;
	char	*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, unsigned int);
	str = ft_uitoa_base(arg, 16);
	if (arg == 0 && flag->prec == 0 && flag->ifprec == 1 && !flag->plus
		&& flag->width == 0)
		return ;
	flag->len = ft_strlen(str);
	flag->hash && arg ? flag->len += 2 : 0;
	cmp_fill_prec_x(flag, arg);
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	!flag->minos ? fill_void_prec_x(box, flag, "debut", arg) :
		(fill_void_prec_x(box, flag, "minos", arg));
	while (str[i] && arg)
		fill_str(box, str[i++]);
	arg == 0 && flag->prec == 1 ? fill_str(box, '0') : 0;
	fill_void_prec_x(box, flag, "end", arg);
	free(str);
}

void	conv_hx_prec(t_printf *box, t_check *flag)
{
	int				i;
	int				s;
	unsigned char	arg;
	char			*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, int);
	str = ft_uitoa_base(arg, 16);
	if (arg == 0 && flag->prec == 0 && flag->ifprec == 1 && !flag->plus
		&& flag->width == 0)
		return ;
	flag->len = ft_strlen(str);
	flag->hash && arg ? flag->len += 2 : 0;
	cmp_fill_prec_x(flag, arg);
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	!flag->minos ? fill_void_prec_x(box, flag, "debut", arg) :
		(fill_void_prec_x(box, flag, "minos", arg));
	while (str[i] && arg)
		fill_str(box, str[i++]);
	arg == 0 && flag->prec == 1 ? fill_str(box, '0') : 0;
	fill_void_prec_x(box, flag, "end", arg);
	free(str);
}

void	conv_jx_prec(t_printf *box, t_check *flag)
{
	int				i;
	int				s;
	uintmax_t		arg;
	char			*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, uintmax_t);
	str = ft_ultoa_base((uintmax_t)arg, 16);
	if (!arg && !flag->prec && flag->ifprec == 1 && !flag->plus && !flag->width)
		return ;
	flag->len = ft_strlen(str);
	flag->hash && arg ? flag->len += 2 : 0;
	cmp_fill_prec_x(flag, arg);
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	!flag->minos ? fill_void_prec_x(box, flag, "debut", arg) :
		fill_void_prec_x(box, flag, "minos", arg);
	while (str[i] && arg)
		fill_str(box, str[i++]);
	arg == 0 && flag->prec == 1 ? fill_str(box, '0') : 0;
	fill_void_prec_x(box, flag, "end", arg);
	free(str);
}

void	conv_lx_prec(t_printf *box, t_check *flag)
{
	int					i;
	int					s;
	unsigned long long	arg;
	char				*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, unsigned long long);
	str = ft_ultoa_base(arg, 16);
	if (!arg && !flag->prec && flag->ifprec == 1 && !flag->plus && !flag->width)
		return ;
	flag->len = ft_strlen(str);
	flag->hash && arg ? flag->len += 2 : 0;
	cmp_fill_prec_x(flag, arg);
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, 'x') : 0;
	!flag->minos ? fill_void_prec_x(box, flag, "debut", arg) :
	(fill_void_prec_x(box, flag, "minos", arg));
	while (str[i] && arg)
		fill_str(box, str[i++]);
	arg == 0 && flag->prec == 1 ? fill_str(box, '0') : 0;
	fill_void_prec_x(box, flag, "end", arg);
	free(str);
}
