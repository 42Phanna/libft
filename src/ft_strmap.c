/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 04:01:22 by phanna            #+#    #+#             */
/*   Updated: 2017/09/25 09:43:00 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tab;

	i = -1;
	if (s)
	{
		if (!(tab = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[++i])
			tab[i] = f(s[i]);
		tab[i] = '\0';
		return (tab);
	}
	return (0);
}
