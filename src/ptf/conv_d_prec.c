/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:30:10 by phanna            #+#    #+#             */
/*   Updated: 2019/01/14 14:45:44 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_d_prec(t_printf *box, t_check *flag)
{
	int		i;
	int		s;
	int		arg;
	char	*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, int);
	flag->modif == 'H' ? (str = (char*)ft_itoa(arg))
			: (str = ft_itoa(arg));
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

void	conv_hd_prec(t_printf *box, t_check *flag)
{
	int			i;
	signed char	arg;
	char		s;
	char		*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, int);
	str = (char*)ft_itoa(arg);
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

void	conv_ld_prec(t_printf *box, t_check *flag)
{
	int		i;
	int		s;
	long	arg;
	char	*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, long);
	str = ft_ltoa(arg);
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

void	conv_zd_prec(t_printf *box, t_check *flag)
{
	int		i;
	int		s;
	size_t	arg;
	char	*str;

	box->i++;
	i = 0;
	s = 0;
	arg = va_arg(box->ap, size_t);
	str = ft_ultoa(arg);
	flag->len = ft_strlen(str);
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
