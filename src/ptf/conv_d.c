/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 03:17:21 by phanna            #+#    #+#             */
/*   Updated: 2019/01/14 16:58:42 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_d(t_printf *box, t_check *flag)
{
	int		i;
	int		arg;
	char	s;
	char	*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, int);
	str = (flag->modif == 'h' ? ft_itoa((short)arg) : ft_itoa(arg));
	flag->len = ft_strlen(str);
	cmp_fill(flag, arg);
	if (flag->zero && arg < 0)
	{
		arg *= -1;
		fill_str(box, '-');
		i++;
		s = 1;
	}
	flag->plus && str[i] != '+' && arg >= 0 && !s ? fill_str(box, '+') : 0;
	!flag->minos ? fill_void(box, flag, "debut") : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void(box, flag, "end") : 0;
	free(str);
}

void	conv_hd(t_printf *box, t_check *flag)
{
	int			i;
	signed char	arg;
	char		s;
	char		*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, int);
	str = ft_itoa(arg);
	flag->len = ft_strlen(str);
	cmp_fill(flag, arg);
	if (flag->zero && arg < 0)
	{
		arg *= -1;
		fill_str(box, '-');
		i++;
		s = 1;
	}
	flag->plus && str[i] != '+' && arg >= 0 && !s ? fill_str(box, '+') : 0;
	!flag->minos ? fill_void(box, flag, "debut") : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void(box, flag, "end") : 0;
	free(str);
}

void	conv_ld(t_printf *box, t_check *flag)
{
	int			i;
	long long	arg;
	char		*str;

	box->i++;
	i = 0;
	arg = va_arg(box->ap, long long);
	str = ft_ltoa(arg);
	flag->len = ft_strlen(str);
	cmp_fill(flag, arg);
	(flag->zero && arg < 0) ? arg *= -1 : 0;
	if (flag->zero && arg < 0)
		fill_str(box, '-');
	(flag->zero && arg < 0) ? i++ : 0;
	!flag->minos ? fill_void(box, flag, "debut") : 0;
	if (arg == 0 && flag->ifprec == 1 && flag->prec == 0)
		free(str);
	if (arg == 0 && flag->ifprec == 1 && flag->prec == 0)
		return ;
	flag->plus && str[i] != '+' && arg >= 0 ? fill_str(box, '+') : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void(box, flag, "end") : 0;
	free(str);
}

void	conv_zd(t_printf *box, t_check *flag)
{
	int			i;
	size_t		arg;
	char		s;
	char		*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, size_t);
	str = ft_ultoa(arg);
	flag->len = ft_strlen(str);
	cmp_fill(flag, arg);
	flag->plus && str[i] != '+' && !s ? fill_str(box, '+') : 0;
	!flag->minos ? fill_void(box, flag, "debut") : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void(box, flag, "end") : 0;
	free(str);
}
