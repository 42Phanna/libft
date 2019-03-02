/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 08:49:18 by phanna            #+#    #+#             */
/*   Updated: 2019/01/14 17:01:41 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_conv	g_tab[] =
{
	{'%', &conv_100},
	{'c', &conv_c},
	{'s', &conv_s},
	{'d', &choose_conv_d},
	{'i', &choose_conv_d},
	{'D', &choose_conv_ld},
	{'o', &choose_conv_o},
	{'O', &choose_conv_lo},
	{'x', &choose_conv_x},
	{'X', &choose_conv_x_up},
	{'u', &conv_u},
	{'U', &conv_lu},
	{'p', &conv_p},
	{'f', &choose_conv_f}
};

void	check_conv(const char *format, t_printf *box, t_check *flag)
{
	size_t i;

	i = 0;
	while (i < (sizeof(g_tab) / sizeof(t_conv)))
	{
		if (format[box->i] == g_tab[i].c)
		{
			g_tab[i].conv(box, flag);
			break ;
		}
		++i;
	}
}

void	choose_conv_d(t_printf *box, t_check *flag)
{
	if ((flag->modif == 'L' || flag->modif == 'l' || flag->modif == 'j')
		&& flag->ifprec == 1)
		return (conv_ld_prec(box, flag));
	if (flag->modif == 'L' || flag->modif == 'l' || flag->modif == 'j')
		return (conv_ld(box, flag));
	if (flag->modif == 'H' && flag->ifprec == 1)
		return (conv_hd_prec(box, flag));
	if (flag->modif == 'H')
		return (conv_hd(box, flag));
	if (flag->modif == 'z' && flag->ifprec == 1)
		return (conv_zd_prec(box, flag));
	if (flag->modif == 'z')
		return (conv_zd(box, flag));
	if (flag->ifprec == 1)
		return (conv_d_prec(box, flag));
	else
		return (conv_d(box, flag));
}

void	choose_conv_o(t_printf *box, t_check *flag)
{
	if ((flag->modif == 'L' || flag->modif == 'l' || flag->modif == 'j')
		&& flag->ifprec == 1)
		return (conv_lo_prec(box, flag));
	if (flag->modif == 'L' || flag->modif == 'l' || flag->modif == 'j')
		return (conv_lo(box, flag));
	if (flag->modif == 'z' && flag->ifprec == 1)
		return (conv_zo_prec(box, flag));
	if (flag->modif == 'z')
		return (conv_zo_prec(box, flag));
	if (flag->ifprec == 1)
		return (conv_o_prec(box, flag));
	else
		return (conv_o(box, flag));
}

void	choose_conv_x(t_printf *box, t_check *flag)
{
	if (flag->modif == 'h' && flag->ifprec == 1)
		return (conv_hx_prec(box, flag));
	if (flag->modif == 'h')
		return (conv_hx(box, flag));
	if ((flag->modif == 'L' || flag->modif == 'z' || flag->modif == 'l')
		&& flag->ifprec == 1)
		return (conv_lx_prec(box, flag));
	if (flag->modif == 'L' || flag->modif == 'z' || flag->modif == 'l')
		return (conv_lx(box, flag));
	if (flag->modif == 'j' && flag->ifprec == 1)
		return (conv_jx_prec(box, flag));
	if (flag->modif == 'j')
		return (conv_jx(box, flag));
	if (flag->ifprec == 1)
		return (conv_x_prec(box, flag));
	else
		return (conv_x(box, flag));
}
