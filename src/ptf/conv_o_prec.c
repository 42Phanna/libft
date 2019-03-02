/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bam <bam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 15:18:32 by bam               #+#    #+#             */
/*   Updated: 2019/01/09 15:01:01 by bam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_o_prec(t_printf *box, t_check *flag)
{
	int		i;
	int		s;
	int		arg;
	char	*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, unsigned int);
	if (flag->width == 0 && flag->prec == 0 && arg == 0)
	{
		flag->hash ? fill_str(box, '0') : 0;
		return ;
	}
	str = ft_uitoa_base(arg, 8);
	flag->len = ft_strlen(str);
	cmp_fill_prec(flag, arg);
	if (!flag->minos)
		fill_void_prec_o(box, flag, "debut", arg);
	else
		fill_void_prec_o(box, flag, "minos", arg);
	while (str[i] && arg)
		fill_str(box, str[i++]);
	fill_void_prec_o(box, flag, "end", arg);
	free(str);
}

void	conv_lo_prec(t_printf *box, t_check *flag)
{
	int					i;
	int					s;
	unsigned long long	arg;
	char				*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, unsigned long long);
	if (flag->width == 0 && flag->prec == 0 && arg == 0)
	{
		flag->hash ? fill_str(box, '0') : 0;
		return ;
	}
	str = ft_uitoa_base(arg, 8);
	flag->len = ft_strlen(str);
	cmp_fill_prec(flag, arg);
	if (!flag->minos)
		fill_void_prec_o(box, flag, "debut", arg);
	else
		fill_void_prec_o(box, flag, "minos", arg);
	while (str[i] && arg)
		fill_str(box, str[i++]);
	fill_void_prec_o(box, flag, "end", arg);
	free(str);
}

void	conv_zo_prec(t_printf *box, t_check *flag)
{
	int		i;
	int		s;
	size_t	arg;
	char	*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, size_t);
	if (flag->width == 0 && flag->prec == 0 && arg == 0)
	{
		flag->hash ? fill_str(box, '0') : 0;
		return ;
	}
	str = ft_ultoa_base(arg, 8);
	flag->len = ft_strlen(str);
	cmp_fill_prec(flag, arg);
	if (!flag->minos)
		fill_void_prec_o(box, flag, "debut", arg);
	else
		fill_void_prec_o(box, flag, "minos", arg);
	while (str[i] && arg)
		fill_str(box, str[i++]);
	fill_void_prec_o(box, flag, "end", arg);
	free(str);
}
