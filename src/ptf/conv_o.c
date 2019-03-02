/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:04:04 by phanna            #+#    #+#             */
/*   Updated: 2019/01/09 15:08:23 by bam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	choose_conv_lo(t_printf *box, t_check *flag)
{
	if (flag->ifprec == 1)
		return (conv_lo_prec(box, flag));
	else
		return (conv_lo(box, flag));
}

void	conv_o(t_printf *box, t_check *flag)
{
	int		i;
	int		arg;
	char	*str;

	box->i++;
	i = 0;
	arg = va_arg(box->ap, unsigned long long);
	str = ft_uitoa_base(arg, 8);
	flag->len = ft_strlen(str);
	cmp_fill_o(flag, arg);
	!flag->minos ? fill_void_o(box, flag, "debut") : 0;
	flag->minos ? fill_void_o(box, flag, "minos") : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void_o(box, flag, "end") : 0;
	free(str);
}

void	conv_lo(t_printf *box, t_check *flag)
{
	int					i;
	unsigned long long	arg;
	char				*str;

	box->i++;
	i = 0;
	arg = va_arg(box->ap, unsigned long long);
	str = ft_ultoa_base(arg, 8);
	flag->len = ft_strlen(str);
	cmp_fill_o(flag, arg);
	!flag->minos ? fill_void_o(box, flag, "debut") : 0;
	flag->minos ? fill_void_o(box, flag, "minos") : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void_o(box, flag, "end") : 0;
	free(str);
}

void	conv_zo(t_printf *box, t_check *flag)
{
	int		i;
	size_t	arg;
	char	*str;

	box->i++;
	i = 0;
	arg = va_arg(box->ap, size_t);
	str = ft_ultoa_base(arg, 8);
	flag->len = ft_strlen(str);
	cmp_fill_o(flag, arg);
	!flag->minos ? fill_void_o(box, flag, "debut") : 0;
	flag->minos ? fill_void_o(box, flag, "minos") : 0;
	while (str[i])
		fill_str(box, str[i++]);
	flag->minos ? fill_void_o(box, flag, "end") : 0;
	free(str);
}
