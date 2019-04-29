/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:20:00 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 14:30:46 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}