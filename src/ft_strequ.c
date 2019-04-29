/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:59:23 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 15:59:35 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] == s2[i]) && s1[i] && s2[i])
			++i;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		return (0);
	}
	return (0);
}

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		if (!n)
			return (1);
		while ((s1[i] == s2[i]) && s1[i] && s2[i] && n - 1)
		{
			++i;
			--n;
		}
		if (s1[i] == s2[i])
			return (1);
		return (0);
	}
	return (0);
}