/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:47:05 by phanna            #+#    #+#             */
/*   Updated: 2019/01/08 12:56:25 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_char(const char *format, t_printf *box)
{
	while (format[box->i])
	{
		if (format[box->i] == '%')
		{
			box->i++;
			check_option(format, box);
		}
		else
			fill_str(box, format[box->i++]);
	}
	write(1, box->str, ft_strlen(box->str));
}

void	fill_str(t_printf *box, char c)
{
	if (box->j < BUFF_SIZE_PTF - 1)
	{
		if (c == '\0')
		{
			write(1, box->str, ft_strlen(box->str));
			ft_bzero(box->str, sizeof(box->str));
			box->j = 0;
			write(1, "\0", 1);
		}
		else
			box->str[box->j++] = c;
	}
	else
	{
		write(1, box->str, ft_strlen(box->str));
		ft_bzero(box->str, sizeof(box->str));
		box->j = 0;
		box->str[box->j++] = c;
	}
	box->len++;
}
