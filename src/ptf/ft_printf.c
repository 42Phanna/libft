/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 09:08:41 by phanna            #+#    #+#             */
/*   Updated: 2018/02/01 19:26:50 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf	box;

	ft_bzero(&box, sizeof(box));
	va_start(box.ap, format);
	test_char(format, &box);
	va_end(box.ap);
	return (box.len);
}
