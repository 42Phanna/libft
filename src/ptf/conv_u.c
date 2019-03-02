/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:03:54 by phanna            #+#    #+#             */
/*   Updated: 2019/01/08 16:51:39 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_u(t_printf *box, t_check *flag)
{
	int					i;
	unsigned int		arg;
	char				*str;

	if (flag->modif == 'L' || flag->modif == 'l' || flag->modif == 'z'
		|| flag->modif == 'j')
	{
		conv_lu(box, flag);
		return ;
	}
	if (flag->ifprec == 1)
		return (conv_u_prec(box, flag));
	box->i++;
	i = 0;
	arg = va_arg(box->ap, unsigned int);
	str = ft_uitoa(arg);
	flag->len = ft_strlen(str);
	cmp_fill(flag, arg);
	!flag->minos ? fill_void(box, flag, "debut") : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void(box, flag, "end") : 0;
	free(str);
}

void	conv_u_prec(t_printf *box, t_check *flag)
{
	int		i;
	int		arg;
	char	*str;

	box->i++;
	i = 0;
	arg = va_arg(box->ap, unsigned int);
	str = ft_uitoa(arg);
	flag->len = ft_strlen(str);
	cmp_fill_prec(flag, arg);
	if (!flag->minos)
		fill_void_prec_u(box, flag, "debut", arg);
	else
		fill_void_prec_u(box, flag, "minos", arg);
	while (str[i] && arg)
		fill_str(box, str[i++]);
	fill_void_prec_u(box, flag, "end", arg);
	free(str);
}

void	conv_lu(t_printf *box, t_check *flag)
{
	int					i;
	unsigned long long	arg;
	char				*str;

	if (flag->prec)
		return (conv_lu_prec(box, flag));
	box->i++;
	i = 0;
	arg = va_arg(box->ap, unsigned long long);
	str = ft_ultoa(arg);
	flag->len = ft_strlen(str);
	cmp_fill(flag, arg);
	if (!flag->minos)
		fill_void(box, flag, "debut");
	if (arg == 0 && flag->ifprec == 1 && flag->prec == 0)
	{
		free(str);
		return ;
	}
	else
		fill_void(box, flag, "minos");
	while (str[i])
		fill_str(box, str[i++]);
	fill_void(box, flag, "end");
	free(str);
}

void	conv_lu_prec(t_printf *box, t_check *flag)
{
	int					i;
	unsigned long long	arg;
	char				*str;

	box->i++;
	i = 0;
	arg = va_arg(box->ap, unsigned long long);
	str = ft_ultoa(arg);
	flag->len = ft_strlen(str);
	cmp_fill_prec(flag, arg);
	if (!flag->minos)
		fill_void_prec(box, flag, "debut", arg);
	if (arg == 0 && flag->ifprec == 1 && flag->prec == 0)
	{
		free(str);
		return ;
	}
	else
		fill_void_prec(box, flag, "minos", arg);
	while (str[i])
		fill_str(box, str[i++]);
	fill_void_prec(box, flag, "end", arg);
	free(str);
}
