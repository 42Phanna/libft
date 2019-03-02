/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:29:02 by phanna            #+#    #+#             */
/*   Updated: 2019/01/08 12:57:09 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_option(const char *format, t_printf *box)
{
	t_check	flag;

	ft_bzero(&flag, sizeof(flag));
	flag.ifprec = -1;
	while (format[box->i] == '-' || format[box->i] == '+'
	|| format[box->i] == '0' || format[box->i] == ' ' || format[box->i] == '#')
	{
		format[box->i] == '-' ? flag.minos = 1 && box->i++ : 0;
		format[box->i] == '+' ? flag.plus = 1 && box->i++ : 0;
		format[box->i] == '0' ? flag.zero = 1 && box->i++ : 0;
		format[box->i] == ' ' ? flag.space = 1 && box->i++ : 0;
		format[box->i] == '#' ? flag.hash = 1 && box->i++ : 0;
	}
	check_width_prec(format, box, &flag);
}

void	check_width_prec(const char *format, t_printf *box, t_check *flag)
{
	while (format[box->i] >= '0' && format[box->i] <= '9')
	{
		flag->width = flag->width * 10 + format[box->i] - 48;
		box->i++;
	}
	if (format[box->i] == '.')
	{
		flag->ifprec = 1;
		box->i++;
		while (format[box->i] >= '0' && format[box->i] <= '9')
		{
			flag->prec = flag->prec * 10 + format[box->i] - 48;
			box->i++;
		}
	}
	check_modif(format, box, flag);
}

void	check_modif(const char *format, t_printf *box, t_check *flag)
{
	format[box->i] == 'h' && format[box->i + 1] == 'h' ? flag->modif = 'H' : 0;
	format[box->i] == 'l' && format[box->i + 1] == 'l' ? flag->modif = 'L' : 0;
	format[box->i] == 'j' ? flag->modif = 'j' : 0;
	format[box->i] == 'z' ? flag->modif = 'z' : 0;
	if (!flag->modif && (format[box->i] == 'h' || format[box->i] == 'l'))
	{
		format[box->i] == 'h' ? flag->modif = 'h' : 0;
		format[box->i] == 'l' ? flag->modif = 'l' : 0;
	}
	flag->modif == 'H' || flag->modif == 'L' ? box->i += 2 : 0;
	if (flag->modif == 'j' || flag->modif == 'z'
		|| flag->modif == 'h' || flag->modif == 'l')
		box->i += 1;
	check_conv(format, box, flag);
}
