/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_up_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bam <bam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:50 by bam               #+#    #+#             */
/*   Updated: 2019/01/24 15:00:02 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

void	conv_x_up_prec(t_printf *box, t_check *flag)
{
	int		i;
	int		s;
	int		arg;
	char	*str;

	box->i++;
	i = -1;
	s = 0;
	arg = va_arg(box->ap, unsigned int);
	str = ft_uitoa_base(arg, 16);
	if (!arg && !flag->prec && flag->ifprec == 1 && !flag->plus && !flag->width)
		return ;
	flag->len = ft_strlen(str);
	if (flag->hash && arg)
		flag->len += 2;
	else if (flag->hash)
		flag->len += 1;
	cmp_fill_prec_x(flag, arg);
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, 'X') : 0;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	conv_x_up_prec3(box, flag, arg, str);
}

void	conv_lx_up_prec(t_printf *box, t_check *flag)
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
	flag->hash ? flag->len += 2 : 0;
	cmp_fill_prec_x(flag, arg);
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, '0') : 0;
	flag->minos == 1 && flag->hash && arg > 0 ? fill_str(box, 'X') : 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	conv_x_up_prec2(box, flag, arg, str);
}

void	conv_x_up_prec2(t_printf *box, t_check *flag, unsigned long long arg
	, char *str)
{
	int	i;

	i = 0;
	if (!flag->minos)
		fill_void_prec_x_up(box, flag, "debut", arg);
	else
		fill_void_prec_x_up(box, flag, "minos", arg);
	while (str[i] && arg)
		fill_str(box, str[i++]);
	fill_void_prec_x_up(box, flag, "end", arg);
	free(str);
}

void	conv_x_up_prec3(t_printf *box, t_check *flag, unsigned int arg
	, char *str)
{
	int	i;

	i = 0;
	if (!flag->minos)
		fill_void_prec_x_up(box, flag, "debut", arg);
	else
		fill_void_prec_x_up(box, flag, "minos", arg);
	while (str[i] && arg)
		fill_str(box, str[i++]);
	fill_void_prec_x_up(box, flag, "end", arg);
	free(str);
}
