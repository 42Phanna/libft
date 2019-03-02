/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:46:34 by phanna            #+#    #+#             */
/*   Updated: 2019/01/14 15:10:48 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	choose_conv_f(t_printf *box, t_check *flag)
{
	if (flag->ifprec)
		return (conv_f_prec(box, flag));
	return (conv_f(box, flag));
}

void	conv_f(t_printf *box, t_check *flag)
{
	int		i;
	double	arg;
	char	s;
	char	*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, double);
	str = ft_ftoa(arg, flag->prec);
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

void	conv_f_prec(t_printf *box, t_check *flag)
{
	int		i;
	int		s;
	double	arg;
	char	*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, double);
	str = ft_ftoa(arg, flag->prec);
	flag->len = ft_strlen(str);
	arg < 0 ? i++ : 0;
	arg < 0 ? flag->len-- : 0;
	cmp_fill_prec(flag, arg);
	if (!flag->minos)
		fill_void_prec(box, flag, "debut", arg);
	else
		fill_void_prec(box, flag, "minos", arg);
	while (str[i] && arg)
		fill_str(box, str[i++]);
	fill_void_prec(box, flag, "end", arg);
	free(str);
}
