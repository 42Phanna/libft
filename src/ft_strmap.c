/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 04:01:22 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 15:57:26 by phanna           ###   ########.fr       */
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

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*tab;

	i = 0;
	if (s)
	{
		if (!(tab = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (tab);
		while (s[i])
		{
			tab[i] = f(i, s[i]);
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (0);
}
